// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    //counters
    int countexam = 0;
    int counthw = 0;
    int countlw = 0;
    int count_reading = 0;
    int count_engagement = 0;
    int count_ccheck = 0;
    int ccheck = 0; //hold

    //exam scores
    double exam_scores = 0;
    double exam1_score = 0;
    double exam2_score = 0;
    double finalexam_score = 0;

    
    double hw_scores = 0;

    double lw_scores = 0;

    double reading_scores = 0;

    double engagement_scores = 0;

    bool ccheck1 = false;
    bool ccheck2 = false;
    double ccheck_scores = 0;


    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            // TODO(student): process exam score
            if(countexam ==0)
            {
                exam1_score = score;
            }
            else
                exam2_score = score;
            countexam++;
            exam_scores += score;
        } else if (category == "final-exam") {
            // TODO(student): process final score
            finalexam_score = score;
            exam_scores+= score;
            countexam++;
        } else if (category == "hw") {
            // TODO(student): process hw score
            counthw++;
            hw_scores+=score;
        } else if (category == "lw") {
            // TODO(student): process lw score
            countlw++;
            lw_scores += score;
        } else if (category == "reading") {
            // TODO(student): process reading score
            reading_scores += score;
            count_reading++;
        } else if (category == "engagement") {
            // TODO(student): process engagement score
            engagement_scores += score;
            count_engagement++;
        }else if  (category == "compile-check") {
            // TODO(student): process compile-check score
            if(count_ccheck == 0 && score == 1)
                ccheck1 = true;
            else if(count_ccheck == 0 && score == 0)
                ccheck1 = false;
            else if(count_ccheck == 1 && score == 1)
                ccheck2 = true;
            else if(count_ccheck == 1 && score == 0)
                ccheck2 = false;
            count_ccheck += 1;
            ccheck_scores += score;
            ccheck++;
        }else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages

    //EXAM AVERAGE
    double exam_average = 0;
    double nonfinal_average = (exam1_score + exam2_score)/2;
    if(finalexam_score > nonfinal_average)
        exam_average = finalexam_score;
    else
    {
        exam_average = exam_scores/3;
    }

    //HOMEWORK AVERAGE
    double hw_average = 0;
    if(counthw>0)
        hw_average = hw_scores/counthw;

    //LW AVERAGE
    double lw_average = 0;
    if(countlw>0)
    {
        if(ccheck1 == true && ccheck2 == true)
        lw_average = (lw_scores/countlw)*100;
        else if (ccheck1 == false || ccheck2 == false)
        {
            lw_average = (lw_scores/countlw)*100;
            lw_average *=.5;
        }
        else if (ccheck1 == false && ccheck2 == false)
            lw_average = 0;
    }
    if(count_ccheck == 0)
        lw_average = 0;
    

    // READING AVERAGE
    double reading = 0;
    if(count_reading>0)
        reading = (reading_scores/count_reading) + 15;
    else
        reading += 15;
    if(reading>100)
        reading = 100;

    //ENGAGEMENT AVERAGE
    double engagement = 0;
    if(count_engagement>0)
        engagement = (engagement_scores/count_engagement) + 15;
    else
        engagement += 15;
    if(engagement>100)
        engagement = 100;

    //COMPILE CHECK AVERAGE
    double compileCheck_average = 0;
    if(count_ccheck>0)
        compileCheck_average = ccheck_scores/count_ccheck;
    ccheck-= compileCheck_average;
    

    // TODO(student): compute weighted total of components
    double weighted_total = 0;
    weighted_total = (exam_average*.4) + (hw_average*.4) + (lw_average*.1) + (reading*.05) + (engagement*.05);

    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    if(weighted_total <= 100 && weighted_total >= 90)
        final_letter_grade = 'A';
    else if(weighted_total < 90 && weighted_total >= 80)
        final_letter_grade = 'B';
    else if(weighted_total < 80 && weighted_total >= 70)
        final_letter_grade = 'C';
    else if(weighted_total < 70 && weighted_total >= 59.5)
        final_letter_grade = 'D';
    else if(weighted_total < 59.5)
        final_letter_grade = 'F';

    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement | compile-check" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
