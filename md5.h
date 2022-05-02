#define F(x,y,z) (x&y)|(!x&z)
#define G(x,y,z) (((x)&(z))|((y)&(~z)))
#define H(x,y,z) ((x)^(y)^(z))
#define I(x,y,z) ((y)^((x)|(~z)))
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))
#define MAGIC_PADDING_NUMBER 448
#define BLOCKSIZE 512

struct context_struct {
    unsigned int a0,b0,c0,d0;
    char* text;
};

struct stat_struct {
    /** Leftshift amount for each round **/
    unsigned int rots0[4];
    unsigned int rots1[4];
    unsigned int rots2[4];
    unsigned int rots3[4];
    unsigned int *rots[4];

    /** constants for addition **/
    unsigned int k[64];

    /** Mock data **/
    int M[16]
};


