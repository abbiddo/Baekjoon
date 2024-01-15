def solution(s, k):

    for i,v in enumerate(s):

        if v == k[0] and is_keyword(s[i:], k):

            return True

    return False

def is_keyword(s, k):

    ki = 0

    for v in s:

        if v.isdigit():

            continue

        else:

            if v == k[ki]:

                ki += 1

                if len(k) == ki - 1:

                    return False

                continue

            else:

                return False

    return True

s = input()

k = input()

print(1 if solution(s,k) else 0)