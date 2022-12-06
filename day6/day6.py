if __name__ == "__main__":
    with open("input.txt") as f:
        f = f.readline()

        for part in [1, 2]:
            win_size = 4 if part == 1 else 14
            for i in range(len(f)):
                window = f[i : i + win_size]
                checker = 0
                for c in window:
                    if window.count(c) == 1:
                        checker += 1
                if checker == win_size:
                    print(f"solution part {part}: {i+win_size}")
                    break
