/**
*	��ģ�����ڶ�����Դ���б�Ҫ������
*	�Լ���ÿ�����Ĵ�Ϊrevd_msg_s��ʽ
*	��֮������Դ�ļ��ϵĲ�����������Դ�ļ���û������
*
*	�ṩ�����¼�������:
*		- �������ڶ�ȡʱ���б�Ҫ�ķ���
*		- �������ݶ�ȡ
*
*------------------------
*	2017-01-24
*	ptsph@foxmail.com
*/
#include <map>
#include <vector>
using namespace std;

#include "vdm_parse_core.h"

#ifndef SRCDATA_H
#define SRCDATA_H

struct revd_msg_s{
	revd_msg_s() :count(0), msg_p(), major_msg_p(NULL){}

	string get_msg_by_count(size_t _count){
		return (msg_p[_count]);
	}
	void set_msg_by_count(size_t _count, const string &_str){
		_str.copy(msg_p[_count], 1024, 0);
	}

	size_t count;
	char msg_p[5][1024];
	char * major_msg_p;
};
#endif /*SRCDATA_H*/

void atoi_s_(const char * _str, size_t _len, size_t *_dst);

/*
*	��ȡ�ַ�$_check���ֵ�$_count������λ�ã������������򷵻�NULL
*		
*	���磺
*	const char * str = "abc,d,efr,sdf";
*	find_char_by_count(str,',',3);
*	�����ص�����','����λ�õ�ָ��
*	
*	NOTE��
*	ע�ⲻ�Ƿ�����һ��λ�õ�ָ�룬
*	��Ϊ�����޷���֤��һ��ָ��(next pointer)����Ч��	
*
*/
const char * find_char_by_count(const char * _str, char _check, size_t _count);

/*	
*	�ҵ������е���Ҫ���Ķο�ʼλ�ã��Ҳ����򷵻�NULL
*
*	���磺
*	const char * str = "20160322 - 07:09:12	!AIVDM,1,1,,A,B6:V`n00=28I9I4W9pQ4swTWQP06,0*71";
*	find_major_beg(str);
*	���������������ͷ��ʾ���ַ�����ָ��
*	20160322 - 07:09:12	!AIVDM,1,1,,A,B6:...
*									  ^
*	NOTE��
*	������Ҫ���ݾʹӴ˿�ʼ�������Ƿ���Ч���ǲ���֤
*
*/
const char * find_major_beg(const char * _str);

/*
*	�ҵ������е���Ҫ���Ķν���λ�ã��Ҳ����򷵻�NULL
*
*	���磺
*	const char * str = "20160322 - 07:09:12	!AIVDM,1,1,,A,B6:V`n00=28I9I4W9pQ4swTWQP06,0*71";
*	find_major_end(str);
*	���������������ͷ��ʾ���ַ�����ָ��
*	20160322 - 07:09:12	!AIVDM,1,1,,A,B6:V`n00=28I9I4W9pQ4swTWQP06,0*71
*									                              ^
*	NOTE��
*	������������ĵ���Ҫ���ݣ�ʹ��find_major_beg��find_major_end�������ʺϲ����ˣ�
*	����ǰ�߷��ص�ֵΪbeg������Ϊend(�Ҷ���ΪNULL)����ô��������������ôд��
*	for(const char * i = beg;i < end;i ++){...}
*	��ô����������ȷ��������ϰ�ߺ�ƽʱдforѭ����ϰ��һ������[beg,end)
*
*/
const char * find_major_end(const char * _str);

/*
*	�ҵ����ĵ�ͷλ�ã��Ҳ����򷵻�NULL
*
*	���磺
*	const char * str = "20160322 - 07:09:12	!AIVDM,1,1,,A,B6:V`n00=28I9I4W9pQ4swTWQP06,0*71";
*	find_msg_header(str);
*
*	���������������ͷ��ʾ���ַ�����ָ��
*	20160322 - 07:09:12	!AIVDM,1,1,,A,B6:V`n00=28I9I4W9pQ4swTWQP06,0*71
*						^
*	
*
*/
const char * find_msg_header(const char * _str);

/*
*	ͬʱ�����ҵ����ĵ�ͷλ�úͽ���λ��
*	
*	NOTE��
*	��ϸ�����뿴find_major_beg��find_major_end����
*
*/
int find_major_beg_end(const char * _str, const char ** _beg, const char ** _end);

/*
*	ƴ�ӱ�����Ҫ���ݣ�����ƴ�ӽ����ʧ�ܷ���NULL
*	
*	���磺
*	���������������ģ�
*	20160322 - 07:09:12	!AIVDM,2,1,3,A,C6:`Mo00AB8l@e4Vv@;NGwv0@b30jbM0@2N00000000,0*56
*	20160322 - 07:09:12	!AIVDM,2,2,3,A,0`3`63S0P,0*20
*	��ƴ�ӽ��Ϊ��
*	C6:`Mo00AB8l@e4Vv@;NGwv0@b30jbM0@2N000000000`3`63S0P
*	
*	NOTE��
*	ƴ�ӽ����Ҫ���ڵ����Ͷ�������ʱ�Ľ���
*
*/
char * cat_major_msg(revd_msg_s * _revd_msg);

/*
*	���ձ����������ܱ���
*	
*	���磺
*	���������������ģ�
*	20160322 - 07:09:12	!AIVDM,2,1,3,A,C6:`Mo00AB8l@e4Vv@;NGwv0@b30jbM0@2N00000000,0*56
*	20160322 - 07:09:12	!AIVDM,2,2,3,A,0`3`63S0P,0*20
*	ʹ��recv_all_msg������Ὣ����洢��$_revd_msg��
*
*
*/
int recv_all_msg(revd_msg_s * _revd_msg,FILE **_fp);

/*
*	���revd_msg_s�ṹ
*	
*	NOTE��
*	�����ζ�Ž������������գ���������Ϊ'\0'
*	�������ͷ�
*/
int clear_revd_msg(revd_msg_s *_revd_msg);

/*
*	���ı������еı��ļ��ص�$_revd_msg_vec�ṹ��
*	revd_msg_s�ṹ���£�
*	struct revd_msg_s{
*		size_t count;
*		char msg_p[5][1024];
*	};
*	
*	
*	
*/
int read_srcdata(const char * _filename, vector<revd_msg_s> &_revd_msg_vec);

int classify_by_user_id(char * _filename,map<size_t,vector<revd_msg_s> > &_userid_map_msg);

int save_by_user_id(map<size_t,vector<revd_msg_s> > &_userid_map_msg);



















