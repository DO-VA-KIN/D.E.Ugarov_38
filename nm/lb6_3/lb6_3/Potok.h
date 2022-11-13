#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>//для ф-ии sscanf

using namespace std;

//интерфейсный класс считывателя
class Vvod
{
public:
	virtual char* Read();
};

static class VvodInt:public Vvod
{
public:
	char* Read();
};

class VvodDouble:public Vvod
{
public:
	char* Read();
};

class VvodString:public Vvod
{
public:
	char* Read();
};



//интерфейсный класс валидатора
class Validator
{
protected:
	virtual void Check(char* str);
};

class ValidatorInt: public Validator
{
public:
	void Check(char* str);
};

class ValidatorDouble : public Validator
{
public:
	void Check(char* str);
};

class ValidatorString : public Validator
{
public:
	void Check(char* str);
};