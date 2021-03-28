favorite_languages = {
    'jen':'python',
    'sarah':'c',
    'edward':'ruby',
    'phil':'python',
}#字典定义
language = favorite_languages['jen'].title()
lan=favorite_languages.get('your','java')
print(f"jen's favorite_language is {language}")
print(f"your favorite_language is {lan}")
