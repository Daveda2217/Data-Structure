// 찾고자 하는 sum = K
// K를 가지는 부분 연속 수열 찾기

// s = 0, e = 0부터 시작.
// 합이 K보다 작거나 같다면 e++
// 그 외 s++
// K를 찾으면 count

// pseudo code

/*
for s in range(n):
    while sum < K && e < n:
        sum += data[e]
        e++
    
    if(sum == K)
        count++
    
    sum-= data[s]
*/