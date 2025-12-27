/* 

At first glance, this problem looks impossible to simulate forward.
Starting from an array of ones and repeatedly replacing an index with the sum of the array? Brutal.

The breakthrough:
Stop thinking forward. Think reverse.
Instead of constructing the target array, reverse the process:
Always pick the largest element
Realize it must have been formed by repeatedly adding the sum of the rest
Reduce it efficiently using modulo
Validate edge cases carefully

*/



class Solution {
    public boolean isPossible(int[] target) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        long sum = 0;

        for (int num : target) {
        sum += num;
        maxHeap.offer(num);
        }

        while (true) {
        int max = maxHeap.poll();
        long rest = sum - max;

        if (max == 1 || rest == 1) return true;
        if (rest == 0 || max <= rest) return false;

        int prev = (int)(max % rest);
        if (prev == 0) return false;

        sum = rest + prev;
        maxHeap.offer(prev);
        }
    }
}


