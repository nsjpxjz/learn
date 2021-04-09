responses = {}
flag = True
while flag:
    name = input("what's your name?")
    response = input("whick mountain would you like to climb someday")
    responses[name]=response
    repeat = input("would you like to let another person respond?(Yes/No)")
    if repeat == 'No':
        flag = False
for name,response in responses.items():
    print(f"{name} would like to climb {response}")