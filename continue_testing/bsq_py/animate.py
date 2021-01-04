''' 
| - animate.py
'''
import pygame
from pygame.transform import rotate as rotate
from pygame.transform import scale as scale
from pygame.surfarray import make_surface as makesurf
from gather import gather as gather

# this is just a main file (for now)
# no class is exposed (for now)

def _estimate_ta(data_size, slices):
    num_cores = multiprocessing.cpu_count()
    print("detected {} cores".format(num_cores))

    reference_time = 22.07 * 4 # a 91x91 picture (cropdata.png), 256 slices on 4 cores
    ref_sliced = reference_time / 256
    ref_resized = ref_sliced / (91*91)
    print("estimated time awaiting is ", str( ref_resized * data_size * slices / num_cores )  )
    return num_cores

def _draw_hud(screen, level, max, info):
        font = pygame.font.SysFont(None, 32)
        data_string = "slice "+str(level+1)+" of "+str(max_level)+". "
        data_string += str(info)
        text_surf = font.render(data_string, 1, (255,255,255))
        text_rect = text_surf.get_rect()
        screen.blit(text_surf, text_rect)

def _dump():
    pass

def _retrieve():
    pass

if __name__ == "__main__":
    
    #pygame shit to make it work    
    pygame.init()
    size_x = 800
    size_y = 800
    screen  = pygame.display.set_mode([size_x, size_y])

    # load data
    max_level = 10
    container = gather("dataset/vader.png", max_level)
    surfaces = []
    analysis = []
    for i in range(max_level):
        surfaces.append(  scale(rotate(makesurf(container.isles[i].get_islands()), -90),(size_x,size_y))  )
        analysis.append(container.analysis[i])
        analysis[i].set_big(50)
        
    # this level
    this_level = 0
    last_level = -1

    #main loop
    main = True
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
        if last_level != this_level:
            surf = surfaces[this_level]
            last_level = this_level
            screen.blit(surf, surf.get_rect())
            _draw_hud(screen,this_level, max_level, analysis[this_level])
        #blit blot
        pygame.display.update()



