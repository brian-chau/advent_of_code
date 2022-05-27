import timeit

if __name__=='__main__':
    with open( 'input.txt' ) as f:
        lines = f.readlines()

    start = timeit.default_timer()
    for i in range( 10_000 ):
        gamma, eps = 0, 0
        first_line = lines[0].strip()
        line_length = len( first_line )
        for i in range( line_length ):
            gamma <<= 1
            eps   <<= 1

            bits = [ line[i] for line in lines ]
            ones = bits.count("1")
            if ones > 500:
                gamma += 1
            else:
                eps   += 1
    stop = timeit.default_timer()

    print( gamma * eps )
    print( stop - start )