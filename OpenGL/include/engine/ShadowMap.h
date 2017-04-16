/*
  *��Ӱ��ͼ.Ҳ������CSMʵ�ֵ�һ����,ԭ�����ļ�����ɾ�ˣ�Ŀǰ�İ汾������ʵ�ֵ�
  *@date:2017-4-10
  *@author:xiaohuaxiong
 */
#ifndef __SHADOW_MAP_H__
#define __SHADOW_MAP_H__
#include<engine/Object.h>
#include<engine/Geometry.h>
//#include<engine/GLProgram.h>
__NS_GLK_BEGIN
class ShadowMap :public Object
{
private:
	unsigned        _framebufferId;
	unsigned        _depthTextureId;
	//�ɵĻ���������,������֡�����������л���ʱ��ʹ��
	int					 _oldFramebufferId;
	//��������Ƿ��ǲ���Ⱦ����,�������־��Ϊtrue��ʱ�򣬱�ʾ����CSM����
	bool					_isDepthLayerArray;
	int                   _numberOfLayer;//���_isDepthLayerArrayΪtrue,������������Ŀ,��������ֵʼ��Ϊ0
	Size                 _shadowMapSize;
private:
	ShadowMap(ShadowMap &);
	ShadowMap();
	bool		initWithMapSize(const Size &mapSize);
	/*
	  @param:mapSize��ʾ������Ӱ��ͼ�ĳߴ�
	  @param:numberOfLayer��ʾ����������������Ŀ
	 */
	bool     initWithMapLayer(const Size &mapSize,const int numberOfLayer);
public:
	~ShadowMap();
	static ShadowMap  *createWithMapSize(const Size &mapSize);
	/*
	  *@param:mapSize��ʾ������Ӱ��ͼ�ĳߴ�
	  @param:numberOfLayer��ʾ����������������Ŀ
	  @note:�������ʧ�ܵĻ�,������һ����ָ��
	 */
	static ShadowMap  *createWithMapLayer(const Size &mapSize,const int numberOfLayer);
	//��ȡ�������,������Ҳ������һ�����������
	const unsigned getDepthTexture()const;
	//�Ƿ��ǲ���������
	const bool   isDepthArrayLayer()const;
	//��ȡ��Ӱ��ͼ�ĳߴ�
	const Size&   getMapSize()const;
	//��ȡ��Ӱ��ͼ�Ĳ����Ŀ
	const int     getMapLayer()const;
	
	//���ǰ�Ļ���������,ͬʱ����ԭ����֡����������
	void   activeShadowFramebuffer();
	//�ָ�ԭ���Ļ���������
	void   restoreFramebuffer();
};

__NS_GLK_END
#endif