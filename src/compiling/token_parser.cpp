#include "../../include/token_parser.hpp"
#include "../../include/exceptions.hpp"

bool TokenParser::isEmpty() const
{
    return tokens_.empty();
}

bool TokenParser::parse(TokenType type)
{
    std::regex_search(input_.cbegin() + offset_, input_.cend(), last_match_, token_regex_.at(type));
    if (!last_match_.empty())
    {
        tokens_.push_back({last_match_.str(), type});
        offset_ += last_match_.position() + last_match_.length();
        return true;
    }
    else
    {
        return false;
    }
}

void TokenParser::thenParse(TokenType type)
{
    bool res__ = parse(type);
    if (last_match_.empty())
    {
        throw custom_exception("kkk");
    }
}

std::vector<Token> TokenParser::getTokens() const
{
    return tokens_;
}

const std::string& TokenParser::getLastToken() const
{
    return tokens_[tokens_.size() - 1].value;
}