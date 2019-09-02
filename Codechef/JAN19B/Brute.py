import math
import random
def brute():
    t = 5
    while True:
        # ss = str(raw_input()).split(" ")
        # n = int(ss[0])
        # p = int(ss[1])+1
        n = random.randint(1, 100)
        p = random.randint(n, 100)
        # print(n,p)
        # p +=1
        mxv = (n/2)+1
        # print(mxv)
        count = 0
        mz = 0
        for i in range(1,p+1):
            for j in range(1,p+1):
                for k in range(1,p+1):
                    val = (((n%i)%j)%k)%n
                    mz = max(mz, val)

        for i in range(1,p+1):
            for j in range(1,p+1):
                for k in range(1,p+1):
                    val = (((n%i)%j)%k)%n
                    # mz = max(mz, val)
                    if(val == mz):
                    #     # print(i,j,k)
                        count +=1

        # print(count)

        import math as m
        val = 0
        if(n<=2):
            val = int(m.pow(p,3))
            # continue
        else:
            maxv = (n//2)+1
            mv = n%maxv
            totl = p - mv
            ans1 = m.pow(totl, 2)
            totm = (p - n) * totl
            ans2 = totm
            totr = (p - n)*(p - n)
            ans3 = totr
            val = (int(ans1+ans2+ans3))

        if not ( val == count):
            print("FAIL :: ", n,p, val , count)

# brute()

def fun():
    for x in range(1, 100000):
        # x = input()
        mxv = (x/2)+1
        mxv = x%mxv
        mxv1 = 0
        for i in range(1, x+1):
            mxv1 = max(mxv1, x%i)

        if not (mxv1 == mxv):
            print(x,mxv, mxv1)
# fun()

def check(s):

    arr = list(map(int, s.split(" ")))
    for i in range(0, len(arr)-1):
        if (math.gcd(arr[i], arr[i+1]) == 1):
            return "FAIL1 " + str(i) +" " +str(arr[i]) +" " + str(arr[i+1])

    if (math.gcd(arr[0], arr[len(arr)-1]) == 1):
        return "FAIL2 " + str(0) +" " +str(arr[0]) +" " + str(arr[len(arr)-1])

    for i in range(0, len(arr)-2):
        if not (math.gcd(arr[i], math.gcd(arr[i+1],arr[i+2])) == 1):
            return "FAIL3 " + str(i) +" " +str(arr[i]) +" " + str(arr[i+1])+" " + str(arr[i+2])

    if not (math.gcd(arr[len(arr)-2], math.gcd(arr[0],arr[len(arr)-1])) == 1):
        return "FAIL4 " + str(0) +" " +str(arr[len(arr)-2]) + " " + str(arr[len(arr)-1]) +" " + str(arr[0])

    if not (math.gcd(arr[len(arr)-1], math.gcd(arr[0],arr[1])) == 1):
        return "FAIL5 " + str(0) +" " +str(arr[len(arr)-1]) + " " + str(arr[0]) + " " + str(arr[1])

    if len(arr) == len(set(arr)):
        for x in arr:
            if(x > 1000000000):
                return "FAIL LIMIT"
        return "PASS"
    else:
        return "FAIL SET"
f = open("out", "r")
for x in f.readlines():
    # print(x)
    print(check(x.strip()))