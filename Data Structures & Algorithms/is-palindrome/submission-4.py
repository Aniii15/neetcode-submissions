class Solution:
    def isPalindrome(self, s: str) -> bool:
        s1 = "".join(s.split(" ")).lower()
        s2 = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"

        for ch in s1:
            if ch not in s2:
                s1 = s1.replace(ch, "")

        for i in range(len(s1)//2):
            if s1[i] != s1[-i-1]:
                return False
                break
        else:
            return True