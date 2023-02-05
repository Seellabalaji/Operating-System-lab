#include <stdio.h>
#define MAX_PAGE_FRAMES 10
#define MAX_PAGE_REFERENCES 20
int page_frames[MAX_PAGE_FRAMES];
int page_reference_string[MAX_PAGE_REFERENCES] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
int page_faults = 0;
int last_used[MAX_PAGE_FRAMES];
int find_page_fault(int page_reference) {
    int i;
    for (i = 0; i < MAX_PAGE_FRAMES; i++) {
        if (page_frames[i] == page_reference) {
            last_used[i] = page_faults;
            return 0;
        }
    }
    return 1;
}

int find_lru() {
    int i, lru = 0;
    for (i = 1; i < MAX_PAGE_FRAMES; i++) {
        if (last_used[i] < last_used[lru]) {
            lru = i;
        }
    }
    return lru;
}

int main() {
    int i, j, current_page, next_page, lru;
    for (i = 0; i < MAX_PAGE_FRAMES; i++) {
        page_frames[i] = -1;
        last_used[i] = -1;
    }
    for (i = 0; i < MAX_PAGE_REFERENCES; i++) {
        current_page = page_reference_string[i];
        if (find_page_fault(current_page)) {
            page_faults++;
            if (page_faults <= MAX_PAGE_FRAMES) {
                for (j = 0; j < MAX_PAGE_FRAMES; j++) {
                    if (page_frames[j] == -1) {
                        page_frames[j] = current_page;
                        last_used[j] = page_faults;
                        break;
                    }
                }
            } else {
                lru = find_lru();
                page_frames[lru] = current_page;
                last_used[lru] = page_faults;
            }
        }
        printf("Page frames: ");
        for (j = 0; j < MAX_PAGE_FRAMES; j++) {
            printf("%d ", page_frames[j]);
        }
        printf("\n");
    }
    printf("Total page faults: %d\n", page_faults);
    return 0;
}

/* Output
Page frames: 1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Page frames: 1 2 -1 -1 -1 -1 -1 -1 -1 -1
Page frames: 1 2 3 -1 -1 -1 -1 -1 -1 -1
Page frames: 1 2 3 4 -1 -1 -1 -1 -1 -1
Page frames: 1 2 3 4 -1 -1 -1 -1 -1 -1
Page frames: 1 2 3 4 -1 -1 -1 -1 -1 -1
Page frames: 1 2 3 4 5 -1 -1 -1 -1 -1
Page frames: 1 2 3 4 5 6 -1 -1 -1 -1
Page frames: 1 2 3 4 5 6 -1 -1 -1 -1
Page frames: 1 2 3 4 5 6 -1 -1 -1 -1
Page frames: 1 2 3 4 5 6 -1 -1 -1 -1
Page frames: 1 2 3 4 5 6 -1 -1 -1 -1
Page frames: 1 2 3 4 5 6 7 -1 -1 -1
Page frames: 1 2 3 4 5 6 7 -1 -1 -1
Page frames: 1 2 3 4 5 6 7 -1 -1 -1
Page frames: 1 2 3 4 5 6 7 -1 -1 -1
Page frames: 1 2 3 4 5 6 7 -1 -1 -1
Page frames: 1 2 3 4 5 6 7 -1 -1 -1
Page frames: 1 2 3 4 5 6 7 -1 -1 -1
Page frames: 1 2 3 4 5 6 7 -1 -1 -1
Total page faults: 7
--------------------------------
Process exited after 0.02655 seconds with return value 0
Press any key to continue . . .
