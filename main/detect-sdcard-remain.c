#include <stdio.h>
#include <ff.h>

void app_main(void)
{
    FATFS *fs;
    DWORD fre_clust, fre_sect, tot_sect;

    /* Get volume information and free clusters of sdcard */
    FRESULT res = f_getfree("/sdcard/", &fre_clust, &fs);
    if (res) {
        return;
    }

    /* Get total sectors and free sectors */
    tot_sect = (fs->n_fatent - 2) * fs->csize;
    fre_sect = fre_clust * fs->csize;


    uint64_t tmp_total_bytes =(uint64_t) tot_sect * FF_SS_SDCARD;
    uint64_t tmp_free_bytes =(uint64_t) fre_sect * FF_SS_SDCARD;

    /* Print the free space in bytes */
    printf("%llu total bytes. %llu free bytes. sector_size=%u", tmp_total_bytes, tmp_free_bytes, FF_SS_SDCARD);
}
