import sys
import re
import getopt


def count(lines):
    """
    Function to count the lines inside a C++ class
    """

    firstClass = True

    currentClassTotalLines = 0
    currentClassLineCount = -1
    currentClassCommentCount = 0

    currentClass = ""

    totalClasses = 0
    totalLines = 0
    totalComments = 0

    for line in lines:
        line = line.strip()

        if not line:
            continue

        m = re.search("^int main.*", line)
        if m is not None:
            totalLines += currentClassLineCount
            totalComments += currentClassCommentCount

            print(currentClass)
            print(
                f'\tLines count: {currentClassLineCount}, Comments count: {currentClassCommentCount}, Comments density: {currentClassCommentCount / currentClassLineCount * 100}%')

            print("Totals: ")
            print(f'\tClasses:\t{totalClasses}')
            print(f'\tLines count:\t{totalLines}')
            print(f'\tComments count:\t{totalComments}')
            print(f'\tComments density:\t{totalComments / totalLines * 100}%')
            print(f'\tLines average:\t{totalLines / totalClasses}')
            print(f'\tComments average:\t{totalComments / totalClasses}')
            break

        m = re.search("^class.*", line)
        if m is not None:
            totalClasses += 1
            currentClass = line

            if not firstClass:
                print(currentClass)
                print(f'\tLines count: {currentClassLineCount}, Comments count: {currentClassCommentCount}, Comments density: {currentClassCommentCount / currentClassLineCount * 100}%')

                totalLines += currentClassLineCount
                totalComments += currentClassCommentCount

                currentClassCommentCount = 0
                currentClassLineCount = 0

                continue
            firstClass = False
            continue

        m = re.search(" *//.*", line)
        if m is not None:
            currentClassCommentCount += 1
            continue

        currentClassLineCount += 1


def open_file(file_input):
    """
    Function to open a file and save each line to a list
    """
    with open(file_input, 'r', encoding='UTF-8') as file_one:
        list_of_lines = file_one.readlines()
    file_one.close()

    return list_of_lines


def main(argv):
    """
    Main Function, handles reading arguments passed in from command line
    """
    input_file = ''
    output_file = ''
    opts, arg = getopt.getopt(argv, "hi:o:", ["ifile=", "ofile="])
    for opt, arg in opts:
        if opt == '-h':
            print('<filename>.py -i <inputfile> -o <outputfile>')
            sys.exit()
        elif opt in ("-i", "--ifile"):
            input_file = arg
        elif opt in ("-o", "--ofile"):
            output_file = arg
        else:
            print('Correct usage is: <filename>.py -i <inputfile> -o <outputfile>')
    print('Input file is', input_file)
    print('Output file is', output_file)
    count(open_file(input_file))

if __name__ == "__main__":
    main(sys.argv[1:])
