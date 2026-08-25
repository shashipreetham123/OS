#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, f;

    printf("Enter No. of Pages and No. of Frames: ");
    scanf("%d %d", &n, &f);

    int pages[n], frames[f];

    printf("Enter Page Reference String: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    int pageHits = 0;
    int pageFaults = 0;

    // Initialize frames
    for (int i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\t\tStatus\n");

    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check whether page is already present
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }

        if (found) {
            pageHits++;
        } else {
            pageFaults++;

            int pos = -1;

            // Find an empty frame
            for (int j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find LRU page
            if (pos == -1) {
                int leastRecent = i;
                
                for (int j = 0; j < f; j++) {
                    int lastUsed = -1;

                    // Find the last occurrence of frames[j]
                    for (int k = i - 1; k >= 0; k--) {
                        if (pages[k] == frames[j]) {
                            lastUsed = k;
                            break;
                        }
                    }

                    if (lastUsed < leastRecent) {
                        leastRecent = lastUsed;
                        pos = j;
                    }
                }
            }

            // Replace the LRU page
            frames[pos] = pages[i];
        }

        // Display current page and frames
        printf("%d\t", pages[i]);

        for (int j = 0; j < f; j++) {
            if (frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }

        if (found) {
            printf("\tPage Hit");
        } else {
            printf("\tPage Fault");
        }

        printf("\n");
    }

    printf("\nTotal Page Hits: %d\n", pageHits);
    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
