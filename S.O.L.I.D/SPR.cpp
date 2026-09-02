// SRP - Single Responsibility Principle
// Uma classe deve ter apenas uma responsabilidade
// é importante dividir a responsabilidades em classes distinta para melhor manutenção do codigo
#include <print>
#include <fstream>
#include <assert.h>

// colocando a responsabilidade em salvar o arquivo em uma classe diferente
// a classe Report não precisa mais ser responsavel por duas ações
// tornando o codigo mais limpo e facil de fazer qualquer manutenção futura
class FileManager {
public:
    static bool saveFile(const std::string &fileName, const std::string &data){
        std::ofstream file(fileName);
        if (file.is_open()){
            file << data;
            file.close();
            std::println("Report saved to '{}'", fileName);
            return true;
        }

        std::println("Failed to open file '{}'", fileName);
        return false;
    }

};

// separando a responsabilidade de gerar e salvar um relatorio
// torna possivel qualquer alteração futura como salvamento em outros formatos e em diferentes locais
class Report{
public:
    void generate(const std::string &title, const std::string &body,
                  const std::string &footer) {
        std::println("Generating report data...");
        m_data = std::format("----- {} ----- \n\n{}\n\n ----- {} -----", title, body, footer);
    }
    
    std::string getData() const { return m_data; }
    
private:
    
    std::string m_data;
};

// funçoes de teste
void FileManager_test(){
    assert(FileManager::saveFile("C:/Users/Murilo Cordeiro/OneDrive/Documentos/VScode/Cpp/S.O.L.I.D/teste.txt", "testing..."));
    assert(!FileManager::saveFile("H:/Users/Murilo Cordeiro/OneDrive/Documentos/VScode/Cpp/S.O.L.I.D/teste.txt", "testing..."));
}

void Report_test(){
    const auto title = "Monthly Sales Report";
    const auto body = "This is the body of the report, datailing sales figures for the mounth.";
    const auto footer = "End of Report";
    
    Report report;
    report.generate(title, body, footer);
    
    assert(report.getData().contains(title));
    assert(report.getData().contains(body));
    assert(report.getData().contains(footer));
}

int main(void){
    Report_test();
    FileManager_test();
    
    Report report;
    report.generate("Monthly Sales Report",
                    "This is the body of the report, datailing sales figures for the mounth.",
                    "End of Report");
    
    FileManager::saveFile("other.txt", report.getData());
    
    return 0;
}