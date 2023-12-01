#include <iostream>
#include <iterator>
#include <string>
#include <vector> // For std::vector
#include <fstream>
#include <regex>

/*
 * Pseudocode
 * Algorithm CodeMetrics( file )
 * 1. Open the file
 * 2. Declare and initialize variables and flags. We are not counting now.
 * 3. For each line in the file
 * * If the line is empty, ignore it and go for the next.
 * * If found a class
 * * * If we are counting: display current result from previous class
 * * * Reset counters for class
 * * * Display name of class found
 * * * We are counting now (use flag)
 * * * Go for next line (continue)
 * * If found the main function
 * * * If we are counting: display current results from the last class
 * * * Stop reading the file
 * * If the line is a comment
 * * * Increase the comment counter
 * * Else
 * * * Increase the line counter
 * 4. Display global results
 * 5. End
*/

int main(int argc, char **argv)
{
    // We ignore index 0
    std::cout << argv[1] << std::endl;
    std::ifstream file;
    std::string line;
    std::vector<std::string> outputs;

    while( std::getline( file, line ) ) {
        outputs.push_back(line);
    }

    for(const auto& i : outputs){
        std::cout << i << std::endl;
    }

    /*
    std::string s = "Some people, when confronted with a problem, think "
        "\"I know, I'll use regular expressions.\" "
        "Now they have two problems.";
 
    std::regex self_regex("REGULAR EXPRESSIONS",
            std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(s, self_regex)) {
        std::cout << "Text contains the phrase 'regular expressions'\n";
    }
 
    std::regex word_regex("(\\w+)");
    auto words_begin = 
        std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();
 
    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " words\n";
 
    const int N = 6;
    std::cout << "Words longer than " << N << " characters:\n";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        if (match_str.size() > N) {
            std::cout << "  " << match_str << '\n';
        }
    }
 
    std::regex long_word_regex("(\\w{7,})");
    std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
    std::cout << new_s << '\n';
    */

    return 0;
}


/*int main(int argc, char **argv){
    FILE* fptr;
    char contents;
    int i = 0, n = 0;

    // 2. Declare and init the variables
    int num_lines = 0;
    int num_class = 0;
    int num_comments = 0;
    int class_lines = 0;
    int class_comments = 0;

    regex_t regex;
    int regex_class;

    // Compile regex
    regex_class = regcomp(&regex, "^class.*", 0);

    // 1. Open the file
    fptr = fopen(argv[1], "r");

    if (fptr == NULL){
        printf("ERROR: File not opened");
    }
    
    // Read in the file to get the size of the file
    do{
        contents = fgetc(fptr);
        n++;
        if(contents == regex_class){
            printf("\n %d FOUND Class!", i);
        }
        // printf("%c", contents);
    }while(contents != EOF);

    printf("n : %d", n);
    // Read in the file to a char array
    char lines[n];
    for(i = 0; i <= n; i++){
        lines[i] = fgetc(fptr);
        printf("%c", lines[i]);
    }



for current in list_of_lines:
        if re.search('^class.*', current) is True:
            class_lines += class_counter_line(current, list_of_lines)
            print(class_lines)
            class_comments += class_counter_comment(current, list_of_lines)
            print(class_comments)
            num_class += 1
        if re.search(' comment CHANGE BACK', current) is True:
            num_comments += 1
            num_lines -= 1
        if re.search('^\s*$', current) is True:
            num_lines -= 1
        if re.search('^int main.*', current) is True:
            print("FOUND! Main")
            break
        num_lines += 1

    print("\nTotals:\n")
    print(F"\tClasses:\t\t{num_class}")
    print(F"\tLines Count:\t\t{num_lines}")
    print(F"\tComments Count:\t\t{num_comments}")
    print(F"\tComments density:\t{(num_comments / num_lines) * 100} %")
    print(F"\tLines Avg:\t\t{(class_lines / num_class)}")
    print(F"\tComments Avg:\t\t{class_comments / num_class}")


def class_counter_line(current, list_of_lines):
    """
    Function to count lines inside of classes and return the number of lines
    """
    class_name = current
    class_lines = 0
    class_comments = 0

    for current in list_of_lines:
        if re.search(' comment CHANGE BACK', current) is True:
            class_comments += 1
            class_lines -= 1
        if re.search('^\s*$', current) is True:
            class_lines -= 1
        if re.search('^};*', current) is True:
            break
        class_lines += 1

    print(F"\n{class_name}")
    print(F"\tLines Count: {class_lines}", end="")
    print(F", Comments Count: {class_comments}", end="")
    print(F", Comments density: {(class_comments / class_lines) * 100} %")
    return class_lines


def class_counter_comment(current, list_of_lines):
    """
    Function to count lines inside of classes and return the number of comments
    """
    class_name = current
    class_lines = 0
    class_comments = 0

    for current in list_of_lines:
        if re.search(' comment CHANGE BACK', current) is True:
            class_comments += 1
            class_lines -= 1
        if re.search('^\s*$', current) is True:
            class_lines -= 1
        if re.search('^};*', current) is True:
            break
        class_lines += 1

    print(F"\n{class_name}")
    print(F"\tLines Count: {class_lines}", end="")
    print(F", Comments Count: {class_comments}", end="")
    print(F", Comments density: {(class_comments / class_lines) * 100} %")
    return class_comments



    fclose(fptr);
}*/
