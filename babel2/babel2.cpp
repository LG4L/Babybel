#include <iostream>
#include <json/json.h>
#include <fstream>
#include <string>

class Book {
private:
    std::string gender;
    std::string title;  // Nommage correct pour les membres privés
    std::string author; 
    int issueDate;
    int examplary;

public:
    // Constructeur avec liste d'initialisation
    Book(const std::string& title, const std::string& author, std::string gender, int issueDate, int examplary)
        : title(title), author(author), issueDate(issueDate), examplary(examplary), gender(gender)
    {
        // Initialisation des membres privés via la liste d'initialisation
    }
    void setTitle(std::string title)
    {
        this->title = title;
    }

    void setAuthor(std::string author)
    {
        this->author = author;
    }

    void setGender(std::string gender)
    {
        this->gender = gender;
    }

    void setExamplary(int examplary)
    {
        this->examplary = examplary;
    }

    void setIssueDate(int issueDate)
    {
        this->issueDate = issueDate;
    }

    std::string getTitle()
    {
        return this->title;
    }

    std::string getAuthor()
    {
        return this->author;
    }

    std::string getGender()
    {
        return this->gender;
    }

    int getExamplary()
    {
        return this->examplary;
    }
    int getIssueDate()
    {
        return this->issueDate;
    };

    // Méthode qui retourne un objet JSON
    Json::Value toJson() const {
        Json::Value bookJson;
        bookJson["Title"] = title;       // Titre dans le JSON
        bookJson["Author"] = author;     // Auteur dans le JSON
        bookJson["IssueDate"] = issueDate; // Date de publication dans le JSON
        bookJson["Gender"] = gender;
        bookJson["Examplary"] = examplary;

        return bookJson;
    }
};
int main() {
    // Crée un objet Livre (book)
    Book book1("Le Petit Prince", "Antoine de Saint-Exupéry", "only2:moyai:", 1943, 3);

    // Conversion de l'objet Livre(book) en JSON
    Json::Value jsonOutput = book1.toJson();

    // Affiche le JSON formaté
    std::cout << jsonOutput.toStyledString() << std::endl;





    std::ofstream file_id;
    file_id.open("file.txt");



    Json::StyledWriter styledWriter;
    file_id << styledWriter.write(jsonOutput);

    file_id.close();


    return 0;
}

