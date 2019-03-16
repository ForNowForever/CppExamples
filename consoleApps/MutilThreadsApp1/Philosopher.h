#include <mutex>
#include <condition_variable>
#include <thread>


#pragma once

class Chopstick;
class Philosopher
{
	Chopstick * m_ckLeft, * m_ckRight;
	std::string m_name;
public:
	Philosopher(std::string name, Chopstick * ckLeft, Chopstick * ckRight);
	~Philosopher();

	void takeLeftCk();
	void takeRightCk();
	void dropLeftCk();
	void dropRightCk();
};

class Chopstick
{
	bool m_isTaken;
	std::string m_name;
	std::string m_masterName;

	std::mutex m_mutex;
	std::condition_variable m_cond;

public:
	Chopstick(std::string name)
	{ 
		m_isTaken = false; 
		m_name = name;
		m_masterName = "";
	};
	~Chopstick() {};

	std::string getName() { return m_name; }

	void dropped();
	void takenBy(std::string byWho);
};

