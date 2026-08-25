#include<stdio.h>

int main() {
	int n, f;

	printf("Enter the No. of Pages and No. of Frames: ");
	scanf("%d %d", &n, &f);

	int pages[n], frames[f];

	printf("Enter Page Reference String: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &pages[i]);
	}

	for(int i = 0; i < f; i++) {
		frames[i] = -1;
	}

	int front = -1;
	int pageHits = 0;
	int pageFaults = 0;
	printf("Page\tFrames\tStatus\n");
	for(int i = 0; i < n; i++) {
		bool found = false;
		printf("%d\t", pages[i]);
		for(int j = 0; j < f; j++) {
			if (frames[j] == pages[i]) {
				found = true;
				break;
			}
		}
		if (found) {
			pageHits++;
		} else {
			front = (front + 1) % f;
			frames[front] = pages[i];
			pageFaults++;
		}

		for (int j = 0; j < f; j++) {
			if(frames[j] == -1) {
				printf("- ");
			}else{
				printf("%d ", frames[j]);
			}
		}
		printf("\t");

		if (found) {
			printf("Page Hit");
		}else{
			printf("Page Fault");
		}

		printf("\n");
	}

	printf("Total Page Hits: %d\n", pageHits);
	printf("Totoal Page Faults: %d\n", pageFaults);
	return 0;
}
