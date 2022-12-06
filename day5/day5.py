def execute_instruction_p1(MOVE, FROM, TO, CONTAINER):
    dest = CONTAINER[TO - 1]
    src = CONTAINER[FROM - 1]

    for i in range(int(MOVE)):
        dest.append(src.pop())


def execute_instruction_p2(MOVE, FROM, TO, CONTAINER):
    dest = CONTAINER[TO - 1]
    src = CONTAINER[FROM - 1]
    stacks_to_move = []

    for i in range(int(MOVE)):
        stacks_to_move.append(src.pop())
    for i in range(int(MOVE)):
        dest.append(stacks_to_move.pop())


def init_container(file):
    with open(file) as f:
        for i in range(9):
            container.append([])
        for line in f:
            for k, item in enumerate(line):
                if item == "X" or item == "\n":
                    continue
                else:
                    container[k].append(item)
        for stack in container:
            stack.reverse()
        return container


if __name__ == "__main__":

    container = []
    container = init_container("input.txt")

    with open("instructions.txt", "r") as f:

        for instruction in f:
            MOVE = int(instruction.split(",")[0])
            FROM = int(instruction.split(",")[1])
            TO = int(instruction.split(",")[2])

            # execute_instruction_p1(MOVE, FROM, TO, container)
            execute_instruction_p2(MOVE, FROM, TO, container)

        for stack in container:
            print(stack[-1])
