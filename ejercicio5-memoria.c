#include <stdio.h>

typedef struct {
    int id;
    int size;
    int allocated_block;
} Process;

typedef struct {
    int id;
    int size;
    int available;
} MemoryBlock;

void allocate(Process *process, MemoryBlock *blocks, int num_blocks) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        if (blocks[i].available >= process->size) {
            process->allocated_block = blocks[i].id;
            blocks[i].available -= process->size;
            break;
        }
    }
}

void print_allocation(Process *processes, int num_processes) {
    int i;
    printf("Proceso\tTamano\tBloque asignado\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t", processes[i].id, processes[i].size);
        if (processes[i].allocated_block == -1) {
            printf("No asignado\n");
        } else {
            printf("%d\n", processes[i].allocated_block);
        }
    }
}

int main() {
    // Definir los procesos y bloques de memoria
    /*Process processes[] = {
        {1, 212, -1},
        {2, 417, -1},
        {3, 112, -1},
        {4, 426, -1}
    };

    MemoryBlock blocks[] = {
        {1, 100, 100},
        {2, 500, 500},
        {3, 200, 200},
        {4, 300, 300},
        {5, 600, 600}
    };*/

    //Caso adicional de prueba
     Process processes[] = {
        {1, 300, -1},
        {2, 150, -1},
        {3, 200, -1},
        {4, 500, -1}
    };

    MemoryBlock blocks[] = {
        {1, 400, 400},
        {2, 200, 200},
        {3, 600, 600},
        {4, 100, 100}
    };

    int num_processes = sizeof(processes) / sizeof(Process);
    int num_blocks = sizeof(blocks) / sizeof(MemoryBlock);

    int i;
    for (i = 0; i < num_processes; i++) {
        allocate(&processes[i], blocks, num_blocks);
    }

    print_allocation(processes, num_processes);

    return 0;
}
