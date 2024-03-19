 i = row;
    j = col;
    while (i < n && j >= 0)
    {
        if (board[i++][j--] == 'Q')
            return false;
    }