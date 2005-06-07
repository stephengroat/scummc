

#define SCC_TO_16BE(x) ((((x)>>8)&0xFF)|(((x)<<8)&0xFF00))
#define SCC_TO_32BE(x) (  SCC_TO_16BE((uint16_t)(((x)>>16)&0xFFFF)) | (SCC_TO_16BE((uint16_t)(x))<<16) )

#define SCC_AT_32BE(x,at)  SCC_TO_32BE( (*((uint32_t*)&x[at])) )
#define SCC_AT_32LE(x,at) (((uint32_t*)&x[at])[0])
#define SCC_AT_32(x,at) (((uint32_t*)&x[at])[0])
#define SCC_AT_16BE(x,at)  SCC_TO_16BE( (*((uint16_t*)&x[at])) )
#define SCC_AT_16LE(x,at) (((uint16_t*)&x[at])[0])
#define SCC_AT_16(x,at) (((uint16_t*)&x[at])[0])


#define MKID(a,b,c,d) ((uint32_t) \
			((d) & 0x000000FF) | \
			((c << 8) & 0x0000FF00) | \
			((b << 16) & 0x00FF0000) | \
			((a << 24) & 0xFF000000))

#define UNMKID(a) (a>>24)&0xFF, (a>>16)&0xFF, (a>>8)&0xFF, a&0xFF

// needed by the room builder
#define SCC_MAX_IM_PLANES 10
#define SCC_MAX_GLOB_SCR  200
#define SCC_MAX_ACTOR     17

// A coomon struct to hold some data
typedef struct scc_data scc_data_t;
struct scc_data {
  uint32_t size;
  uint8_t data[0];
};

// the bloody SCC_LIST :)
#define SCC_LIST_ADD(list,last,c) if(c){                  \
  if(last) last->next = c;                                \
  else list = c;                                          \
  for(last = c ; last && last->next ; last = last->next); \
}

#define SCC_LIST_FREE(list,last) while(list) {            \
  last = list->next;                                      \
  free(list);                                             \
  list = last;                                            \
}

scc_data_t* scc_data_load(char* path);