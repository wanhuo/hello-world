/*
 *������Ⱦ����,�����Ҫ��һ��ͳһ�ķ�ʽ��Ⱦ����,����ʵ�������,Ȼ�����GLContext::addChild
 *2016-10-9 10:14:15
 *@Author:С����
 */
#ifndef  __RENDER_OBJECT_H__
#define __RENDER_OBJECT_H__
#include<engine/GLObject.h>
#include<engine/Geometry.h>
/*
 *draw������flag�ĺ���,��μ�GLState.h enum _tDrawFlag
 */
class     RenderObject :public  GLObject
{
protected:
	float            _deltaTime;
private:
	RenderObject(RenderObject &);
protected:
	RenderObject(){ _deltaTime = 0.0f; };
	~RenderObject(){};
public:
	virtual       void           update(float    _deltaTime){};
	virtual       void           draw(Matrix        &_projMatrix, unsigned       flag){};
};
#endif