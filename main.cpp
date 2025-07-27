#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// run program = ctrl + shift + b
// file OOP = workspace

class Task{
    private:
        int id;
        string nama;
        string deadline;
        string prioritas;
        bool isSelesai;
    
    public:
        Task(int id, string nama, string deadline, string prioritas) {
            this->id = id;
            this->nama = nama;
            this->deadline = deadline;
            this->prioritas = prioritas;
            this->isSelesai = false;
        };

        //* Task Method
        void tandaiSelesai() {
            this->isSelesai = true;
            cout << "Tugas " << this->nama << " telah selesai" << endl;
        }

        void tampilkanInfo() {
            string status = (this->isSelesai) ? "Selesai" : "Belum Selesai";
            cout << this->id << "\t" << this->nama << "\t" << this->deadline << "\t" << prioritas << "\t\t" << status << endl;
        }

        //* Getter
        int getId() {
            return this->id;
        }

        string getNama() {
            return this->nama;
        }

        string getDeadline() {
            return this->deadline;
        }

        string getPrioritas() {
            return this->prioritas;
        }

        bool getStatus() {
            return this->isSelesai;
        }

        //* Setter
        void setNama(string newName) {
            this->nama = newName;
        }

        void setDeadline(string newDeadline) {
            this->deadline = newDeadline;
        }

        void setPrioritas(string newPrioritas) {
            this->prioritas= newPrioritas;
        }
};

class TaskManager{
    public:
        vector<Task*> daftarTugas;
        int nextId;
        
        TaskManager() {
            this->nextId = 1;   
        }

        //* Create Method
        void tambahTugas();

        //* Read Method
        void tampilkanSemuaTugas();
        
        void tampilkanTugasBelumSelesai();
        
        void tampilkanTugasPrioritas();
        
        //* Update Method
        void tandaiTugasSelesai(int id);

        void ubahNama(int id);

        void ubahDeadline(int id);

        void ubahPrioritas(int id);

        //* Delete Method
        void hapusTugas(int id);

        //* Destructor
        ~TaskManager(){
            for (Task* tugas : daftarTugas) {
                delete tugas;
            }
        };

};

int getOption();

int main(int argc, char const *argv[])
{
    TaskManager taskManager;

    enum option {
        AddTask = 1,
        ShowAllTask,
        ShowUndoneTask,
        ShowPriorityTask,
        MarkTaskAsDone,
        SetName,
        SetDeadline,
        SetPriority,
        DeleteTask,
        Exit
    };

    while (true) {
        system("cls");
        int pilihan = getOption();

        switch (pilihan) {
            case AddTask:
                taskManager.tambahTugas();
                break;
            case ShowAllTask:
                if (taskManager.daftarTugas.size() == 0) {
                    cout << "Kamu masih belum memiliki tugas" << endl;
                    break;
                }

                taskManager.tampilkanSemuaTugas();
                break;
            case ShowUndoneTask:
                if (taskManager.daftarTugas.size() == 0) {
                    cout << "Kamu masih belum memiliki tugas" << endl;
                    break;
                }

                taskManager.tampilkanTugasBelumSelesai();
                break;
            case ShowPriorityTask:
                if (taskManager.daftarTugas.size() == 0) {
                    cout << "Kamu masih belum memiliki tugas" << endl;
                    break;
                }

                taskManager.tampilkanTugasPrioritas();
                break;
            case MarkTaskAsDone: {
                if (taskManager.daftarTugas.size() == 0) {
                    cout << "Kamu masih belum memiliki tugas" << endl;
                    break;
                }

                int doneID;
                taskManager.tampilkanSemuaTugas();
                cout << "Masukkan ID tugas: ";
                cin >> doneID;
                taskManager.tandaiTugasSelesai(doneID);
                break;
            }
            case SetName: {
                if (taskManager.daftarTugas.size() == 0) {
                    cout << "Kamu masih belum memiliki tugas" << endl;
                    break;
                }
                int nameID;
                taskManager.tampilkanSemuaTugas();
                cout << "Masukkan ID tugas: ";
                cin >> nameID;
                taskManager.ubahNama(nameID);
                break;
            }
            case SetDeadline: {
                if (taskManager.daftarTugas.size() == 0) {
                    cout << "Kamu masih belum memiliki tugas" << endl;
                    break;
                }
                int deadlineID;
                taskManager.tampilkanSemuaTugas();
                cout << "Masukkan ID tugas: ";
                cin >> deadlineID;
                taskManager.ubahDeadline(deadlineID);
                break;
            }
            case SetPriority: {
                if (taskManager.daftarTugas.size() == 0) {
                    cout << "Kamu masih belum memiliki tugas" << endl;
                    break;
                }
                int priorityID;
                taskManager.tampilkanSemuaTugas();
                cout << "Masukkan ID tugas: ";
                cin >> priorityID;
                taskManager.ubahPrioritas(priorityID);
                break;
            }
            case DeleteTask: {
                if (taskManager.daftarTugas.size() == 0) {
                    cout << "Kamu masih belum memiliki tugas" << endl;
                    break;
                }

                int deleteID;
                taskManager.tampilkanSemuaTugas();
                cout << "Masukkan ID tugas: ";
                cin >> deleteID;
                taskManager.hapusTugas(deleteID);
                break;
            }
            case Exit:
                cout << "Program Selesai" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid, coba lagi." << endl;
                break;
        }

        while (true) {
            char lanjut;
            cout << "======================================" << endl;
            cout << "Lanjut? (y/n): ";
            cin >> lanjut;
            if (lanjut == 'y' || lanjut == 'Y') {
                break;
            } else if (lanjut == 'n' || lanjut == 'N') {
                cout << "Program Selesai" << endl;
                return 0;
            }
        }
    }
}


//* Menu
int getOption() {
    int input;
    cout << "\n======================================" << endl;
    cout << "         TO-DO LIST APPLICATION       " << endl;
    cout << "======================================" << endl;

    cout << "\n[ ADD TASK ]" << endl;
    cout << "  1. Tambahkan Tugas" << endl;

    cout << "\n[ DISPLAY TASKS ]" << endl;
    cout << "  2. Tampilkan Semua Tugas" << endl;
    cout << "  3. Tampilkan Tugas Belum Selesai" << endl;
    cout << "  4. Tampilkan Tugas Prioritas" << endl;

    cout << "\n[ UPDATE TASKS ]" << endl;
    cout << "  5. Tandai Tugas Selesai" << endl;
    cout << "  6. Ubah Nama" << endl;
    cout << "  7. Ubah Deadline" << endl;
    cout << "  8. Ubah Prioritas" << endl;

    cout << "\n[ DELETE TASKS ]" << endl;
    cout << "  9. Hapus Tugas" << endl;

    cout << "\n[ EXIT ]" << endl;
    cout << " 10. Keluar" << endl;
    cout << "======================================" << endl;
    cout << "Pilih opsi (1-10): ";
    cin >> input;
    // while (!cin >> input) {
    //     cout << "Pilih (1-6)? ";
    //     cin.clear();
    //     cin.ignore(1000, '\n');
    // }
    return input;
}

//* Task Manager Method
//* Create Method
void TaskManager::tambahTugas() {
    string nama, deadline, strPrioritas;
    int prioritas;

    cout << "Masukkan nama tugas: ";
    cin.ignore();
    getline(cin, nama);

    cout << "Masukkan deadline tugas (dd-mm-yyyy): ";
    getline(cin, deadline);

    do {
        cout << "Masukkan prioritas tugas (1-3): ";
        cin >> prioritas;
        cin.ignore();
    } while (prioritas < 1 || prioritas > 3);
    
    if (prioritas == 1) {
        strPrioritas = "Rendah";
    } else if (prioritas == 2) {
        strPrioritas = "Sedang";
    } else {
        strPrioritas = "Tinggi";
    }

    Task* newTask = new Task(nextId, nama, deadline, strPrioritas);
    daftarTugas.push_back(newTask);
    cout << "Tugas berhasil ditambahkan" << endl;

    this->nextId+=1;
}

//* Read Method
void TaskManager::tampilkanSemuaTugas() {
    cout << "ID" << "\t" << "Nama Tugas" << "\t" << "Deadline" << "\t" << "Prioritas" << "\t" << "Status" << endl;
    for (int i = 0; i < daftarTugas.size(); i++) {
        this->daftarTugas[i]->tampilkanInfo();
    }
}

void TaskManager::tampilkanTugasBelumSelesai() {
    bool adaTugasBelumSelesai = false;

    for (int i = 0; i < daftarTugas.size(); i++) {
        if (daftarTugas[i]->getStatus() == false) {
            cout << "ID" << "\t" << "Nama Tugas" << "\t" << "Deadline" << "\t" << "Prioritas" << "\t" << "Status" << endl;
            adaTugasBelumSelesai = true;
            break;
        }
    }
    for (int i = 0; i < daftarTugas.size(); i++) {
        if (daftarTugas[i]->getStatus() == false) {
            daftarTugas[i]->tampilkanInfo();
        }
    }

    if (!adaTugasBelumSelesai) {
        cout << "Semua Tugas Selesai" << endl;
    }
}

void TaskManager::tampilkanTugasPrioritas() {
    cout << "ID" << "\t" << "Nama Tugas" << "\t" << "Deadline" << "\t" << "Prioritas" << "\t" << "Status" << endl;
    for (Task* task : daftarTugas) {
        if (task->getPrioritas() == "Tinggi") {
            task->tampilkanInfo();
        }
    }
    for (Task* task : daftarTugas) {
        if (task->getPrioritas() == "Sedang") {
            task->tampilkanInfo();
        }
    }
    for (Task* task : daftarTugas) {
        if (task->getPrioritas() == "Rendah") {
            task->tampilkanInfo();
        }
    }
}

//* Update Method
void TaskManager::tandaiTugasSelesai(int id) {
    for (int i = 0; i < daftarTugas.size(); i++) {
        if (daftarTugas[i]->getId() == id) {
            daftarTugas[i]->tandaiSelesai();
            return;
        }
    }
    cout << "ID tugas tidak ditemukan" << endl;
}

void TaskManager::ubahNama(int id) {
    for (Task* task : daftarTugas) {
        if (task->getId() == id) {
            string newName;
            cin.ignore();
            cout << "Masukkan nama baru: ";
            getline(cin, newName);
            while (true) {
                char lanjut;
                cout << "Yakin ingin merubah nama dari \"" << task->getNama() << "\" menjadi \"" << newName << "\"? (y/n) ";
                cin >> lanjut;
                if (lanjut == 'y' || lanjut == 'Y') {
                    task->setNama(newName);
                    cout << "Berhasil merubah nama menjadi \"" << newName << "\"" << endl;
                    return;
                } else if (lanjut == 'n' || lanjut == 'N') {
                    cout << "Perubahan dibatalkan" << endl;
                    return;
                }
            } 
        }
    }
    cout << "ID tidak ditemukan" << endl;
}

void TaskManager::ubahDeadline(int id) {
    for (Task* task : daftarTugas) {
        if (task->getId() == id) {
            string newDeadline;
            cin.ignore();
            cout << "Masukkan deadline baru (dd-mm-yyyy): ";
            getline(cin, newDeadline);
            while (true) {
                char lanjut;
                cout << "Yakin ingin merubah deadline dari \"" << task->getDeadline() << "\" menjadi \"" << newDeadline << "\"? (y/n) ";
                cin >> lanjut;
                if (lanjut == 'y' || lanjut == 'Y') {
                    task->setDeadline(newDeadline);
                    cout << "Berhasil merubah deadline menjadi \"" << newDeadline << "\"" << endl;
                    return;
                } else if (lanjut == 'n' || lanjut == 'N') {
                    cout << "Perubahan dibatalkan" << endl;
                    return;
                }
            }
        }
    }
    cout << "ID tidak ditemukan" << endl;
}

void TaskManager::ubahPrioritas(int id) {
    for (Task* task : daftarTugas) {
        if (task->getId() == id) {
            int prioritas;
            string newPrioritas;
            do {
                cout << "Masukkan prioritas tugas (1-3): ";
                cin >> prioritas;
                cin.ignore();
            } while (prioritas < 1 || prioritas > 3);
            if (prioritas == 1) {
                newPrioritas = "Rendah";
            } else if (prioritas == 2) {
                newPrioritas = "Sedang";
            } else {
                newPrioritas = "Tinggi";
            }
            while (true) {
                char lanjut;
                cout << "Yakin ingin merubah prioritas dari \"" <<task->getPrioritas() << "\" menjadi \"" << newPrioritas << "\"? (y/n) ";
                cin >> lanjut;
                if (lanjut == 'y' || lanjut == 'Y') {
                    task->setPrioritas(newPrioritas);
                    cout << "Berhasil merubah prioritas menjadi \"" << newPrioritas << "\"" << endl;
                    return;
                } else if (lanjut == 'n' || lanjut == 'N') {
                    cout << "Perubahan Dibatalkan" << endl;
                    return;
                }
            }
        }
    }
    cout << "ID tidak ditemukan" << endl;
}

//* Delete Method
void TaskManager::hapusTugas(int id) {
    int i = 0;
    while (i < daftarTugas.size()) {
        if (daftarTugas[i]->getId() == id) {
            cout << "Tugas " << daftarTugas[i]->getNama() << " telah dihapus" << endl;
            delete daftarTugas[i];
            daftarTugas.erase(daftarTugas.begin() + i);
            return;
        }
        i++;
    }
    cout << "ID tugas tidak ditemukan" << endl;
}