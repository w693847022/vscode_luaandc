#include<stdafx.h>
using namespace std;

#include<iostream>
using namespace std;

struct point{
public:
	point(int xx,int yy):x(xx),y(yy){};
	int x;
	int y;
	bool operator ==(point p1)
	{
		if(x == p1.x && y == p1.y)
		{
			return true;
		}
		return false;
	}
};

static int map[6][6] = {
	{1,1,1,1,1,1,},
	{1,1,0,1,1,1,},
	{1,0,1,1,1,1,},
	{1,1,1,1,1,1,},
	{1,1,0,1,0,1,},
	{1,1,1,1,1,1,},};
bool PushRangePoint(point sPoint,stack<point>& mapStack,vector<point>& pointQue)
{
	int mm[8][2] = {{1,1},{-1,1},{-1,-1},{1,-1},{1,0},{-1,0},{0,1},{0,-1}};
	int x = sPoint.x;
	int y = sPoint.y;
	if(x<0 || x>6 || y < 0 || y > 6)
	{
		return false;
	}
	bool hasPoint = false;
	for(int i = 0;i<8;i++)
	{
		int xx = x + mm[i][0];
		int yy = y + mm[i][1];
		if((xx>=0 && xx<=5)&&(yy>=0 && yy<=5) && map[xx][yy] == 1)
		{
			point p(xx,yy);
			bool out = false;
			for(auto t : pointQue)
			{
				if(t == p)
				{
					out =  true;
				}
			}
			if(out) 
				continue;
			mapStack.push(p);
			hasPoint = true;
		}
	}
	return hasPoint;
}
void main()
{
	point sPoint(0,0);//开始点
	point tPoint(5,5);//结束点
	vector<point> m_PointQue;
	vector<point> m_endPointQue(36);
	m_PointQue.push_back(sPoint);
	stack<point> m_RangeMap;//压入最后路径点范围1格的可走点
	//压入开始点
	PushRangePoint(sPoint,m_RangeMap,m_PointQue);
	while(m_RangeMap.size()>0)//如果有点就一直执行
	{
		point p = m_RangeMap.top();
		m_PointQue.push_back(p);
		m_RangeMap.pop();
		if(p == tPoint && m_endPointQue.size() > m_PointQue.size())//找到目标点
		{
			m_endPointQue = m_PointQue;
			m_PointQue.pop_back();
		}
		if(!PushRangePoint(p,m_RangeMap,m_PointQue))
		{
			//当前点没有可走路径
			m_PointQue.pop_back();
		}
	}
	cout<<"路径:"<<endl;

	while(m_PointQue.size()>0)
	{
		cout<<"x:"<<m_PointQue.back().x<<" y:"<<m_PointQue.back().y<<endl;
		m_PointQue.pop_back();
	}
}