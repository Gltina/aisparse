/*
	��ģ�����ڶ�����Դ���б�Ҫ������.
	�����������Ķ�����Դ�������͵�.
	
	�ṩ�����¼�������:
	1) ��ԭʼ���ݱ��İ���user_id(MMSI)����(ֻ��vdm�ĲŻ���з���).
	2) ������(vdm����)��user_idΪ�ļ������б���.
	
------------------------
	2017-01-24
	ptsph@foxmail.com
*/
#include <map>
#include <vector>
using namespace std;

#include "vdm_parse.h"

#ifndef SRCDATA_H
#define SRCDATA_H

struct revd_msg_s{
	size_t count;
	char msg_p[5][1024];
};

#endif /*SRCDATA_H*/

char * find_char_by_count(char * _str,char _check,size_t _count);

char * find_major_beg(char * _str);

char * find_major_end(char * _str);

char * find_msg_header(char * _str);

char * find_msg_channel(char * _str);

int find_major_beg_end(char * _str,char ** _beg,char ** _end);

int cat_major_msg_special(revd_msg_s * _revd_msg,char * _major_msg,size_t _len);

char * cat_major_msg(revd_msg_s * _revd_msg,size_t _len);

int recv_all_msg(revd_msg_s * _revd_msg,FILE **_fp);

int clear_revd_msg(revd_msg_s *_revd_msg);

int classify_by_user_id(char * _filename,map<size_t,vector<revd_msg_s> > &_userid_map_msg);

int save_by_user_id(map<size_t,vector<revd_msg_s> > &_userid_map_msg);

