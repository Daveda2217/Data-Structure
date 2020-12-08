// 외우고 있으면 유용한 코드!

int binary_index[MAXSIZE];

int prefix_sum(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += binary_index[i];
        i -= (i & -i);
    }
    return res;
}

void binary_update(int i, int number)
{
    while (i <= MAXSIZE)
    {
        binary_index[i] += number;
        i += (i & -i);
    }
}

int interval_sum(int s, int e)
{
    return prefix_sum(e) - prefix_sum(s - 1);
}

int lower_bound(int key)
{
    int s = 0;
    int e = MAXSIZE - 1;

    while (s < e)
    {
        int mid = (s + e) / 2;
        if (prefix_sum(mid) >= key)
            e = mid;
        else
            s = mid + 1;
    }
    return e;
}

int lower_bound(int key)
{
    int s = 0;
    int e = MAXSIZE - 1;

    while (s < e)
    {
        int mid = (s + e) / 2;
        if (prefix_sum(mid) >= key)
            e = mid;
        else
            s = mid + 1;
    }
    return e;
}