#pragma once

#include <vector>
#include <time.h>

using namespace std;

template <typename T>
class Alea
{
public:
	Alea()
	{
		srand(time(NULL));
	}

	void Put(const T object)
	{
		m_objects.push_back(object);
	}

	void Put(const vector<T> objects)
	{
		for (auto itr = objects.cbegin(); itr != objects.end(); ++itr)
		{
			m_objects.push_back(*itr);
		}
	}

	T Get()
	{
		auto size = m_objects.size();
		int index = rand() % size;
		return m_objects[index];
	}

	~Alea()
	{
	}
private:
	vector<T> m_objects;
};

