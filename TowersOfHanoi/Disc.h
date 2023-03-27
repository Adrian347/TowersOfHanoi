#ifndef DISC_H
#define DISC_H

class Disc
{
private:
	int m_size;
public:
	Disc() { m_size = 1; }
	Disc(int _size) { m_size = _size; }
	int GetSize() { return m_size; }
	void SetSize(int _size) { m_size = _size; }
	void DrawDisc();
};
#endif

