#include <string>
#include <string_view>

class Session
{
public:
  Session(std::string_view word) : m_word{word}, m_misses{'+', '+', '+', '+', '+', '+'}
  {
  }

  std::string_view getWord() const { return m_word; }

  auto &getGuessed() const { return m_guessed; }
  auto &getMisses() const { return m_misses; }

  void addGuessed(char ch) { m_guessed.emplace_back(ch); }

  void pushMiss(char ch)
  {
    m_misses.emplace_back(ch);
    m_misses.erase(m_misses.begin());
  }

private:
  std::string_view m_word{};
  std::vector<char> m_guessed{};
  std::vector<char> m_misses{};
};
