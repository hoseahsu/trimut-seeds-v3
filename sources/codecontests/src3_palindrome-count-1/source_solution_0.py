def isPalindrome(s):
  lf = 0
  ri = len(s)-1
  while lf <= ri:
    if s[lf] != s[ri]:
      return 0
    lf += 1
    ri -= 1
  return 1

def getPalindromes(s):
  palindromes = []
  lf = 0
  ri = len(s)
  while lf <= ri:
    subri = lf+1
    while subri <= ri:
      t = s[lf:subri]
      if isPalindrome(t):
        palindromes.append(t)
      subri += 1
    lf += 1
  return palindromes


print len(getPalindromes(raw_input()))