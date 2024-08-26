#include <stdio.h>

int main() {
    int N, K;
    int order[101];
    int plug[101] = {0};
    int unplugs = 0;

    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &order[i]);
    }

    for (int i = 0; i < K; i++) {
        int current = order[i];
        int plugged_in = 0;

        for (int j = 0; j < N; j++) {
            if (plug[j] == current) {
                plugged_in = 1;
                break;
            }
        }

        if (plugged_in) continue;
      
        int empty_spot = -1;
        for (int j = 0; j < N; j++) {
            if (plug[j] == 0) {
                empty_spot = j;
                break;
            }
        }

        if (empty_spot != -1) {
            plug[empty_spot] = current;
            continue;
        }

        int farthest = -1;
        int index_to_unplug = -1;

        for (int j = 0; j < N; j++) {
            int last_use = 0;
          
            for (int k = i + 1; k < K; k++) {
                if (order[k] == plug[j]) {
                    last_use = k;
                    break;
                }
            }

            if (last_use == 0) {
                index_to_unplug = j;
                break;
            }

            if (last_use > farthest) {
                farthest = last_use;
                index_to_unplug = j;
            }
        }
      
        plug[index_to_unplug] = current;
        unplugs++;
    }
  
    printf("%d\n", unplugs);

    return 0;
}
