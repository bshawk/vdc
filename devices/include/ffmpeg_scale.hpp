#ifndef __FFMPEG_SCALE_H__
#define __FFMPEG_SCALE_H__
#pragma once

#ifndef INT64_C
#define INT64_C(c) (c ## LL)
#define UINT64_C(c) (c ## ULL)
#endif

#ifndef BOOL
    typedef int BOOL;
#endif
#if 0
#ifndef byte
    typedef char byte;
#endif
#endif

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif 

extern "C"
{
#include "libswscale/swscale.h"
}

//Scale�㷨
enum SwsAlogrithm
{
    SWS_SA_FAST_BILINEAR    = 0x1,
    SWS_SA_BILINEAR         = 0x2,
    SWS_SA_BICUBIC          = 0x4,
    SWS_SA_X                = 0x8,
    SWS_SA_POINT            = 0x10,
    SWS_SA_AREA             = 0x20,
    SWS_SA_BICUBLIN         = 0x40,
    SWS_SA_GAUSS            = 0x80,
    SWS_SA_SINC             = 0x100,
    SWS_SA_LANCZOS          = 0x200,
    SWS_SA_SPLINE           = 0x400,
};

//��Ƶͼ���ʽ
enum PicFormat
{
    SWS_PF_NONE         = PIX_FMT_NONE,
    SWS_PF_YUV420P      = PIX_FMT_YUV420P,
    SWS_PF_RGB24        = PIX_FMT_RGB24,
    SWS_PF_BGR24        = PIX_FMT_BGR24,
    SWS_PF_ARGB         = PIX_FMT_ARGB,
    SWS_PF_RGBA         = PIX_FMT_RGBA,
    SWS_PF_ABGR         = PIX_FMT_ABGR,
    SWS_PF_BGRA         = PIX_FMT_BGRA,
};


class FFmpegScale
{
public:
    FFmpegScale(void);
    ~FFmpegScale(void);

    //�����������ͼƬ�����Լ�Scale�㷨
    void SetAttribute(PicFormat srcFormat, PicFormat dstFormat, SwsAlogrithm enAlogrithm = SWS_SA_FAST_BILINEAR);

    //Scale
    BOOL Scale(
        unsigned char *pSrc, int nSrcW, int nSrcH, int nSrcPicth,
        unsigned char *pDst, int nDstW, int nDstH, int nDstPicth
        );

private:

    //��ʼ��
    BOOL Init();

    //����ʼ��
    void DeInit();

    SwsContext* m_pSwsContext;      //SWS����
    PicFormat m_srcFormat;          //Դ���ظ�ʽ
    PicFormat m_dstFormat;          //Ŀ�����ظ�ʽ
    SwsAlogrithm m_enAlogrithm;     //Resize�㷨

    int m_nSrcW, m_nSrcH;           //Դͼ����
    int m_nSrcPicth;                //Դͼ���һ�����ݵĳ���
    int m_nSrcSlice[4];             //Դͼ�������������ʼ��ַƫ��
    int m_nSrcStride[4];            //Դͼ�������һ�����ݵĳ���

    int m_nDstW, m_nDstH;           //Ŀ��ͼ����
    int m_nDstPicth;                //Ŀ��ͼ���һ�����ݵĳ���
    int m_nDstSlice[4];             //Ŀ��ͼ�������������ʼ��ַƫ��
    int m_nDstStride[4];            //Ŀ��ͼ�������һ�����ݵĳ���

};

//����
FFmpegScale::FFmpegScale(void)
{
    m_pSwsContext = NULL;
    m_srcFormat = SWS_PF_NONE;  
    m_dstFormat = SWS_PF_NONE;  
    m_enAlogrithm = SWS_SA_FAST_BILINEAR;

    m_nSrcW = m_nSrcH = 0;          
    m_nSrcPicth = 0;                
    m_nDstW = m_nDstH = 0;
    m_nDstPicth = 0;
    for (int i=0; i<4; i++)
    {
        m_nSrcSlice[i] = -1;
        m_nSrcStride[i] = 0;
        m_nDstSlice[i] = -1;
        m_nDstStride[i] = 0; 
    }
}

//����
FFmpegScale::~FFmpegScale(void)
{
    DeInit();
}

/***************************************************************************//**
* �������ƣ�    SetAttribute
* ����������    �����������ͼƬ�����Լ�Scale�㷨��
* ��    ����    srcFormat   >> Դͼ���ʽ��
* ��    ����    dstFormat   >> Ŀ��ͼ���ʽ��
* ��    ����    enAlogrithm >> Scale�㷨��
* �� �� ֵ��    
*******************************************************************************/
void FFmpegScale::SetAttribute(PicFormat srcFormat, PicFormat dstFormat, SwsAlogrithm enAlogrithm)
{
    m_srcFormat = srcFormat;
    m_dstFormat = dstFormat;
    m_enAlogrithm = enAlogrithm;
    DeInit();
}

/***************************************************************************//**
* �������ƣ�    Init
* ����������    ��ʼ����
* �� �� ֵ��    ִ�гɹ�����TRUE�����򷵻�FALSE��
* ����˵����    
*******************************************************************************/
BOOL FFmpegScale::Init()
{
    //����Ԥ�����ù����������ʽ
    if (SWS_PF_NONE == m_srcFormat || SWS_PF_NONE == m_dstFormat)
    {
        return FALSE;
    }

    //����ʼ��
    DeInit();

    //����sws����
    m_pSwsContext = sws_getContext(
        m_nSrcW,
        m_nSrcH,
        (PixelFormat)m_srcFormat,
        m_nDstW,
        m_nDstH,
        (PixelFormat)m_dstFormat,
        (int)m_enAlogrithm,
        NULL, 
        NULL, 
        NULL);
    if (NULL == m_pSwsContext)
    {
        return FALSE;
    }

    //��ʼ��ԴSlice��Stride
    if (m_srcFormat == SWS_PF_YUV420P)
    {
        m_nSrcSlice[0] = 0;
        m_nSrcSlice[1] = m_nSrcW * m_nSrcH;
        m_nSrcSlice[2] = m_nSrcW * m_nSrcH * 5 / 4;
        m_nSrcSlice[3] = -1;

        m_nSrcStride[0] = m_nSrcW;
        m_nSrcStride[1] = m_nSrcW / 2;
        m_nSrcStride[2] = m_nSrcW / 2;
        m_nSrcStride[3] = 0;

    }
    else
    {
        m_nSrcSlice[0] = 0;
        m_nSrcSlice[1] = -1;
        m_nSrcSlice[2] = -1;
        m_nSrcSlice[3] = -1;

        m_nSrcStride[0] = m_nSrcPicth;
        m_nSrcStride[1] = 0;
        m_nSrcStride[2] = 0;
        m_nSrcStride[3] = 0;
    }

    //��ʼ��Ŀ��Slice��Stride
    if (m_dstFormat == SWS_PF_YUV420P)
    {
        m_nDstSlice[0] = 0;
        m_nDstSlice[1] = m_nDstW * m_nDstH;
        m_nDstSlice[2] = m_nDstW * m_nDstH * 5 / 4;
        m_nDstSlice[3] = -1;

        m_nDstStride[0] = m_nDstW;
        m_nDstStride[1] = m_nDstW / 2;
        m_nDstStride[2] = m_nDstW / 2;
        m_nDstStride[3] = 0;

    }
    else
    {
        m_nDstSlice[0] = 0;
        m_nDstSlice[1] = -1;
        m_nDstSlice[2] = -1;
        m_nDstSlice[3] = -1;

        m_nDstStride[0] = m_nDstPicth;
        m_nDstStride[1] = 0;
        m_nDstStride[2] = 0;
        m_nDstStride[3] = 0;
    }
    return TRUE;
}

/***************************************************************************//**
* �������ƣ�    DeInit
* ����������    ����ʼ����
* �� �� ֵ��    
* ����˵����    
*******************************************************************************/
void FFmpegScale::DeInit()
{
    if (NULL != m_pSwsContext)
    {
        sws_freeContext(m_pSwsContext);
    }
    m_pSwsContext = NULL;
}

/***************************************************************************//**
* �������ƣ�    Scale
* ����������    Scale
* ��    ����    pSrc            >> Դͼ���ڴ���ʼ��ַ��
* ��    ����    nSrcW           >> Դͼ���ȣ�
* ��    ����    nSrcH           >> Դͼ��߶ȣ�
* ��    ����    nSrcPicth       >> Դͼ��ÿ�����ݵĳ��ȣ�YUV��ʽ�ĸ�ֵ�������ɣ���
* ��    ����    pDst            << Ŀ��ͼ���ڴ���ʼ��ַ��
* ��    ����    nDstW           >> Ŀ��ͼ���ȣ�
* ��    ����    nDstH           >> Ŀ��ͼ��߶ȣ�
* ��    ����    nDstPicth       >> Ŀ��ͼ��ÿ�����ݵĳ��ȣ�YUV��ʽ�ĸ�ֵ�������ɣ���
* �� �� ֵ��    ִ�гɹ�����TRUE�����򷵻�FALSE��
*******************************************************************************/
BOOL FFmpegScale::Scale(unsigned char *pSrc, int nSrcW, int nSrcH, int nSrcPicth, unsigned char *pDst, int nDstW, int nDstH, int nDstPicth)
{
    //����κβ��������仯������Ҫ���³�ʼ��
    if (nSrcW != m_nSrcW || nSrcH != m_nSrcH || m_nSrcPicth != m_nSrcPicth
        || nDstW != m_nDstW || nDstH != m_nDstH || m_nDstPicth != m_nDstPicth)
    {
        m_nSrcW = nSrcW;
        m_nSrcH = nSrcH;
        m_nSrcPicth = nSrcPicth;
        m_nDstW = nDstW;
        m_nDstH = nDstH;
        m_nDstPicth = nDstPicth;
        DeInit();
    }

    //���δ�ܳɹ���ʼ��������ʧ��
    if (NULL == m_pSwsContext && !Init())
    {
        return FALSE;
    }

    //������Scale����
    unsigned char *srcSlice[4], *dstSlice[4];
    for (int i=0; i<4; i++)
    {
        srcSlice[i] = m_nSrcSlice[i] < 0 ? NULL : (pSrc + m_nSrcSlice[i]);
        dstSlice[i] = m_nDstSlice[i] < 0 ? NULL : (pDst + m_nDstSlice[i]);
    }
    return sws_scale
        (
        m_pSwsContext,
        (uint8_t **)srcSlice,
        m_nSrcStride,
        0,
        m_nSrcH,
        (uint8_t **)dstSlice,
        m_nDstStride
        ) == m_nSrcH;
}

#endif /* __FFMPEG_SCALE_H__ */
