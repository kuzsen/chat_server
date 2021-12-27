//#pragma once
#ifndef CHATINFO_H
#define CHATINFO_H

#include <event.h>
#include <list>
#include "chat_database.h"

using namespace std;

#define MAXNUM    1024     //��ʾȺ������

struct User               // �����û���
{
	string name;		  // �����û���
	struct bufferevent* bev; // ÿ�������û��Ļ���������
};
typedef struct User User;

struct GroupUser	// Ⱥ��Ա��
{
	string name;
};

typedef struct GroupUser GroupUser;

struct Group	//Ⱥ����
{
	string name;	// Ⱥ������
	list<GroupUser>* l; // Ⱥ����Ⱥ��Ա����
};
typedef struct Group Group;

class Server;

class ChatInfo
{
	friend class Server;
private:
	list<User>* online_user;     //�����������ߵ��û���Ϣ��������������ʽ
	list<Group>* group_info;     //��������Ⱥ����Ϣ������������
	ChatDataBase* mydatabase;    //���ݿ����

public:
	ChatInfo();
	~ChatInfo();

	bool info_group_exist(string);
	bool info_user_in_group(string, string);
	void info_group_add_user(string, string);
	struct bufferevent* info_get_friend_bev(string);
	string info_get_group_member(string);
	void info_add_new_group(string, string);
};

#endif