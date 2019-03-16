#include "Philosopher.h"
#include <iostream>


Philosopher::Philosopher(std::string name, Chopstick * ckLeft, Chopstick * ckRight):
	m_name(name), m_ckLeft(ckLeft), m_ckRight(ckRight)
{
}
Philosopher::~Philosopher()
{
}

void Philosopher::takeLeftCk()
{
	std::cout << m_name.c_str() << " wanna take " << m_ckLeft->getName().c_str() << std::endl;
	m_ckLeft->takenBy(m_name);
}
void Philosopher::takeRightCk()
{
	std::cout << m_name.c_str() << " wanna take " << m_ckRight->getName().c_str() << std::endl;
	m_ckRight->takenBy(m_name);
}

void Philosopher::dropLeftCk()
{
	m_ckLeft->dropped();
}

void Philosopher::dropRightCk()
{
	m_ckRight->dropped();
}



void Chopstick::takenBy(std::string byWho)
{
	//std::lock_guard<std::mutex> lg(m_mutex);
	std::unique_lock<std::mutex> uqLck(m_mutex);
	while (m_isTaken)
	{
		std::cout << byWho.c_str() << " is waiting " << m_name.c_str() << std::endl;
		m_cond.wait(uqLck);
	}
	std::cout << m_name.c_str() << " is Taken by " << byWho.c_str() << std::endl;
	m_masterName = byWho;
	m_isTaken = true;
}

void Chopstick::dropped()
{
	std::cout << m_name.c_str() << " is Dropped by " << m_masterName.c_str() << std::endl;
	m_masterName = "";
	m_isTaken = false;
	m_cond.notify_one();
}
