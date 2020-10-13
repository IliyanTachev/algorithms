#include <iostream>
using namespace std;

void print_rearrangement(char queue[], int n){
    for(int i=0;i<n;i++){
        cout << queue[i];
    }
    cout << endl;
}

int main(){
    int n = 0;
    cout << "Enter count of queue members: ";
    cin >> n;

    char queue[n+1];
    for(int i=0;i<n;i++){
        cin>>queue[i];
    }

    bool is_rearrangement_possible = false;
    for(int i=0;i<n;i++){
        if(queue[i] == '-'){
            is_rearrangement_possible = true;
            break;
        }
    }

    int temp_counter = 0, max_occurences = 0;
    int temp_start_indx = 0, temp_end_indx = 0, max_start_indx = 0,
            max_end_indx = 0, best_position = 0, best_distance = -1, temp_distance = 0;
    bool flag = false;
    if(is_rearrangement_possible){
        for(int i=0;i<=n;i++){
            if(queue[i] == '-'){
                if(temp_counter == 0) temp_start_indx = i;
                temp_counter++;
                flag = true;
            } else if(flag){
                temp_end_indx = i-1;

                if(temp_counter > max_occurences && (best_distance == -1 || (i - (best_position+1) > best_distance ))) {
                    max_occurences = temp_counter;
                    max_start_indx = temp_start_indx;
                    max_end_indx = temp_end_indx;
                    if(max_start_indx - 1 < 0) best_position = 0;
                    else if(max_end_indx + 1 == n) best_position = n-1;
                    else best_position = (max_start_indx+max_end_indx)/2;
                    best_distance = (best_position) - (max_start_indx);
                    if(best_position == 0) best_distance = max_end_indx;
                }
                temp_counter = 0;
                flag = false;
            }
        }

        queue[best_position] = 'M';
        print_rearrangement(queue, n);
        cout << best_distance << endl; // best_distance
    } else cout << -1 << endl;

    return 0;
}
