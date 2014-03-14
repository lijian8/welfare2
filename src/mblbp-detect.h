#ifndef __MBLBP_DETECT__
#define __MBLBP_DETECT__

#include <opencv/cv.h>

#ifdef _OPENMP
#include <omp.h>
#endif

typedef struct MBLBPWeak_
{
    int x;
    int y;
    int cellwidth;
    int cellheight;
    int* p[16]; // fast pointer
    int look_up_table[59]; // look up table
} MBLBPWeak;

typedef struct MBLBPStage_
{
    int count;
    int threshold;
    MBLBPWeak * weak_classifiers;
} MBLBPStage;

typedef struct MBLBPCascade_
{
    int count;
    int win_width;
    int win_height;
    int sum_image_step;
    MBLBPStage * stages;
} MBLBPCascade;

MBLBPCascade * LoadMBLBPCascade(const char * filename );
void ReleaseMBLBPCascade(MBLBPCascade ** ppCascade);

CvSeq * MBLBPDetectMultiScale( const IplImage* img, //����ͼ��
                               MBLBPCascade * pCascade, //������
                               CvMemStorage* storage, //�ڴ�
                               int scale_factor1024x, //ɨ�贰������ϵ�����Ǹ�������1024���������1.1���˴�ӦΪ1024*1.1=1126
                               int min_neighbors, //������С������
                               int min_size, //��Сɨ�贰�ڴ�С�������ڿ�ȣ�
							   int max_size=0); //���ɨ�贰�ڴ�С�������ڿ�ȣ�
#endif
