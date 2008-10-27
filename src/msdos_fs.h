
#define MSDOS_SUPER_MAGIC 0x4d44 /* MD */

#define packed __attribute__ ((packed))

#define p packed

struct msdos_boot_sector {
	char jump[3];                   /* 0  - Boot strap short or near jump */
	char banner[8];                 /* 3  - Name - can be used to special case
				                partition manager volumes */
	unsigned short sector_size p;   /* 11 - bytes per logical sector */
	unsigned char cluster_size;     /* 13 - sectors/cluster */
	unsigned short res_sect p;      /* 14 - reserved sectors */
	unsigned char fats;	        /* 16 - number of FATs */
	unsigned short dir_entries p;   /* 17 - root directory entries */
	unsigned short sectors p;       /* 19 - number of sectors */
	unsigned char media;	        /* 21 - media code (unused) */
	unsigned short fat_length p;    /* 22 - sectors/FAT */
	unsigned short secs_track p;    /* 24 - sectors per track */
	unsigned short heads p;	        /* 26 - number of heads */
	unsigned long hidden p;	        /* 28 - hidden sectors (unused) */
	unsigned long total_sect p;     /* 32 - number of sectors (if sectors == 0) */
	unsigned char physdrive;	/* 36 physical drive ? */
	unsigned char _reserved;	/* 37 reserved */
	unsigned char dos4;		/* 38 DOS > 4.0 diskette */
	unsigned long serial p;       	/* 39 serial number */
	unsigned char label[11];	/* 43 disk label */
	char fat_type[8];		/* 54 FAT type */
#ifdef USE_2M
	unsigned char res_2m;		/* 62 reserved by 2M */
	unsigned char CheckSum;		/* 63 2M checksum (not used) */
	unsigned char fmt_2mf;		/* 64 2MF format version */
	unsigned char wt;		/* 65 1 if write track after format */
	unsigned char rate_0;		/* 66 data transfer rate on track 0 */
	unsigned char rate_any;	/* 67 data transfer rate on track<>0 */
	unsigned short BootP p;		/* 68 offset to boot program */
	unsigned short Infp0 p;		/* 70 T1: information for track 0 */
	unsigned short InfpX p;		/* 72 T2: information for track<>0 */
	unsigned short InfTm p;		/* 74 T3: track sectors size table */
	unsigned char junk[126 - 76];	/* 76 remaining data */
#else
	unsigned char junk[126 - 62];	/* 76 remaining data */
#endif
        unsigned short bootid p;        /* 510 should be 0xAA55 */
};

#undef p
