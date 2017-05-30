#include <cstdio>
#include <cstring>
/*
*	��ģ�鸺���Դ�ļ����ݽ��в���
*
*	@time:2017-05-30
*	@author:ptsph@foxmail.com
*
*/
#ifndef SRCDATA_H_INCLUDED
#define SRCDATA_H_INCLUDED

/*
*	�������ַ���תΪ���ַ��أ������ַ������ַ��򷵻�0
*
*	���磺
*	const char * str = "123456";
*	char dst[6];
*	atoi_s_(str,6,dst);
*	���ú�����dstΪ����123456
*	
*
*/

void atoi_s_(const char * _str, size_t _len, size_t *_dst);

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

#endif