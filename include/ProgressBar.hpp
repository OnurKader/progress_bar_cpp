#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class ProgressBar
{
public:
	/* Takes in a char for filling up the bar and the size fo the bar */
	explicit ProgressBar(char not_done_char = ' ', char done_char = '#', std::size_t length = 81) :
		m_length {length}, m_empty_char {not_done_char}, m_full_char {done_char}
	{
		m_bar.reserve(length + 2);
		m_bar.push_back('[');
		m_bar.append(std::string(length, not_done_char));
		m_bar.push_back(']');
	}

	static void end() { std::cout << std::endl; }

	void reset()
	{
		m_pos = 1;
		std::fill(std::next(m_bar.begin()), std::prev(m_bar.end()), m_empty_char);
	}

	/* Fills the bar upto a given number */
	void fillUpCells(std::size_t cells)
	{
		for(std::size_t i = 1; i < std::min(cells, m_length); i++)
		{
			m_bar[i] = m_full_char;

			std::cout << '\r';

			for(char c: m_bar)
				std::cout << c;

			std::cout << std::flush;
		}

		m_pos = cells;
	}

	/* Fills the bar one by one */
	void fillUp()
	{
		m_bar[m_pos++] = m_full_char;

		std::cout << '\r';

		for(char c: m_bar)
			std::cout << c;

		std::cout << std::flush;
	}

	// TODO: Clean this up
	/* Displays the percentage beside the bar */
	void displayPercentage() const
	{
		const float percent = ((float)m_pos / (float)(m_length)) * 100;
		std::cout << (int)percent << "%";
	}

	std::size_t todo = 0;
	std::size_t done = 0;

	/* Shows tasks done out of the tasks to be done */
	void displayTasksDone() const { std::cout << '(' << done << '/' << todo << ')' << std::flush; }

private:
	std::size_t m_length;
	std::size_t m_pos {1};
	char m_empty_char;
	char m_full_char;
	std::string m_bar;
};
