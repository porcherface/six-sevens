''' 
| - animate.py
'''
import pygame
from pygame.transform import rotate as rotate
from pygame.transform import flip as flip
from pygame.surfarray import make_surface as makesurf
from gather import gather as gather

#pygame animation to show results

SQUARE_COLOR = [40,240,30]
def _estimate_ta(data_size, slices):
    num_cores = multiprocessing.cpu_count()
    print("detected {} cores".format(num_cores))

    reference_time = 22.07 * 4 # a 91x91 picture (cropdata.png), 256 slices on 4 cores
    ref_sliced = reference_time / 256
    ref_resized = ref_sliced / (91*91)
    print("estimated time awaiting is ", str( ref_resized * data_size * slices / num_cores )  )
    return num_cores

def _draw_hud(screen, level, max_level, info):
        font = pygame.font.SysFont(None, 20)
        data_string = "slice "+str(level+1)+" of "+str(max_level)+". "
        data_string += str(info)
        text_surf = font.render(data_string, 1, (255,255,255))
        text_rect = text_surf.get_rect()
        screen.blit(text_surf, text_rect)

#function returns a list of snapshots!
def animate():
    # load data
    max_level = 10
    container = gather("dataset/vader.png", max_level)
    #we try a tuple
    (size_x, size_y) = container.get_imgsize()

    #pygame shit to make it work    
    pygame.init()
    clock = pygame.time.Clock()
    screen  = pygame.display.set_mode([size_x, size_y])
    
    snaps = []
    surfaces = []
    analysis = []

    for i in range(max_level):
        surfaces.append(flip(rotate(makesurf(container.isles[i].get_islands()), -90), 1, 0))
        analysis.append(container.analysis[i])
        print(analysis[i].bsq)

    # this level
    this_level = 0
    last_level = -1

    #main loop
    main = True
    fake_time = 0
    
    while main:
        # get key press
        events = pygame.event.get()
        for event in events:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    this_level += 1 
                    if this_level == max_level:
                        this_level -= 1

                if event.key == pygame.K_DOWN:
                    this_level -= 1
                    if this_level == -1:
                        this_level += 1
                
                if event.key == pygame.K_SPACE:
                    main = False

        #render accordingly
        surf = surfaces[this_level]
        screen.blit(surf, surf.get_rect())

        # bsq blinking square
        rect_sizes = analysis[this_level].bsq
        left   = rect_sizes[1]
        top    = rect_sizes[2]
        width  = rect_sizes[0]
        height = rect_sizes[0]

        #prepare blinking surface
        blinking_square = pygame.Surface((width,height))
        square_color = SQUARE_COLOR
        blinking_square.fill(square_color)

        #now i have to scale width and height?
        bsq_rect = pygame.Rect(left, top, width, height)
        if int(fake_time / 10) % 2 == 0:
            screen.blit(blinking_square, bsq_rect)

        _draw_hud(screen,this_level, max_level, analysis[this_level])
        #blit blot
        pygame.display.update()
        snaps.append(screen.copy())
        fake_time += 1
        clock.tick(30)
    
    return snaps

# pygame snaps to image
def _dump(snaps):
    for idx, snap in enumerate(snaps):
        print("saving frame ",idx)
        pygame.image.save_extended(snap, "output/snaps/snap"+'{:03d}'.format(idx)+".png")

def _make_movie():
    import glob 
    import cv2
    
    img_array = []
    for filename in sorted(glob.glob('output/snaps/snap*.png')):
        print("reading ", filename)
        img = cv2.imread(filename)
        height, width, layers = img.shape
        size = (width,height)
        img_array.append(img)
     
    print("size is: ", size)

    #fourcc = cv2.cv.CV_FOURCC(*'mp4v') 
    out = cv2.VideoWriter('output/movie.mp4',cv2.VideoWriter_fourcc(*'mp4v'), 30, size)
 
    for i in range(len(img_array)):
        out.write(img_array[i])
    out.release()

if __name__ == "__main__":
    # a whole video routine
    # phase 1: _dump(animate())
    #snaps = animate()
    #_dump(snaps)
    #_make_movie()

    #or just watch...
    animate()