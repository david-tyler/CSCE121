# include <iostream>
using std::cin, std::cout, std::endl;

struct backQueue {
    char* array = nullptr;
    int capacity = 0;
    int size = 0;
};
 
void push(backQueue& queue, char character) {
    // TODO: push()

    
    if(queue.capacity > queue.size) //if the capacity is bigger than size no need to resize
    {
        if(queue.capacity > 1)
        {
            char old_char = queue.array[0]; // the first character in the array to for pushing up
            queue.array[0] = character; // character pushed in the front
            for(int i = 1; i < queue.capacity; i++)
            {
                char next_char = queue.array[i]; //next character to be pushed, index +1
                queue.array[i] = old_char; // swapping
                old_char = next_char;// setting it to next character to be pushed
            } 
            queue.size +=1; 
        }
    }
    else // if capcity is not bigger than the size we need to resize
    {
       
        if(queue.array == nullptr)
        {
        
            queue.capacity = 1;//if array is nullptr increase the capacity
            queue.array = new char[queue.capacity];
            queue.array[0] = character;
            queue.size+=1;
        }
        else // if array is not null ptr double the capcity
        {
            int old_capacity = queue.capacity; // varibale for the old capacity of the array before doubling for copying 
            queue.capacity *= 2;//doubling the array

            char* ary = new char[queue.capacity]; // new array for copying
    
            for(int i = 0; i<old_capacity; i++)
            {
                ary[i] = queue.array[i]; //copy the old array into the new
            }
            //Performing the push
            char old_char = ary[0];//first value of the array to be pushed up
            ary[0] = character;//setting the first character to the desired one
            for(int i = 1; i < queue.capacity; i++)//less than new capacity
            {
                char next_char = ary[i];//next character to be pushed
                ary[i] = old_char;//pushing the old character
                old_char = next_char;//setting the old character to the next character pushed
            } 

            queue.size +=1; //increment the size of the array

            delete[] queue.array;//deleting the old array
            queue.array = ary;//setting it to the new one
        }
        
    }
    
   
}
 
char pop(backQueue& queue) {
    // TODO: pop()
    if(queue.size == 0) // no elements return '\0'
    {
        return '\0';
    }
    else
    {
        char popped = queue.array[queue.size-1]; // value to be returned

        char* ary = new char[queue.capacity]; // new array to be copied
        queue.size-=1; //decreasing size of the array
    
        for(int i = 0; i<queue.size; i++)
        {
            ary[i] = queue.array[i]; // copying the old array up until size -1
      
        }

        delete[] queue.array; // deallocating array
        queue.array = ary; // copying the new array into the struct's array

        return popped; // value returned
    }
    
}
 
int main() {
    backQueue q;
 
    push(q, 'a');
   
    std::cout << pop(q) << '\n';
    push(q, 'b');
    push(q, 'c');
   
    std::cout << pop(q) << '\n';
 
    // OPTIONAL TODO: add more test cases
   
    delete[] q.array;
}
