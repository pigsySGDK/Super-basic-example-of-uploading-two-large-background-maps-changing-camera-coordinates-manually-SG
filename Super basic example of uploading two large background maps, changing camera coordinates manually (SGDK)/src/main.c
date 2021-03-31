/*
Pigsy 
March 2021

A super simple example of using the MAP method to display two large backgrounds.
The position of the "camera" for each of the maps of each background layer has to be changed manually in the code.
*/

#include <genesis.h>
#include <resources.h>

Map* bgb;
Map* bga;

u16 bgBaseTileIndex[2];


int main()
{
    u16 ind;
    VDP_setScreenWidth320();

    VDP_setPalette(PAL0, bgb_map.palette->data);
    VDP_setPalette(PAL1, bga_map.palette->data);

    ind = TILE_USERINDEX;
    bgBaseTileIndex[0] = ind;
    VDP_loadTileSet(&bga_tileset, ind, DMA);
    ind += bga_tileset.numTile;
    bgBaseTileIndex[1] = ind;
    VDP_loadTileSet(&bgb_tileset, ind, DMA);
    ind += bgb_tileset.numTile;

    bga = MAP_create(&bga_map, BG_A, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, bgBaseTileIndex[0]));
    bgb = MAP_create(&bgb_map, BG_B, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, bgBaseTileIndex[1]));

    //Change these manually to adjust the camera position for each background map 
    //(coordinates are for the x and y of the top left hand corner of each "camera")
    MAP_scrollTo(bga, 1000, 25);
    MAP_scrollTo(bgb, 25, 25);


    while(1)
    {
        
        SYS_doVBlankProcess();
    }

    MEM_free(bga);
    MEM_free(bgb);

    return (0);
}

