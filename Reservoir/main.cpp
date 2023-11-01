#include "Reservoir.h"
#include <iostream>
#include <vector>
using namespace std;

#pragma region Special_Abilities
void ClearScrean() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tReservoir" << endl;
}
void Enter() {
	string enter;
	cin.ignore();
	do {
		cout << "Press enter to continue: "; getline(cin, enter);
	} while (!enter.empty());
}
#pragma endregion

bool PrintAllReservoir(vector<Reservoir>& reservoirs) {

	if (reservoirs.size() > 0) {

		for (int i = 0; i != reservoirs.size(); i++) {
			cout << i + 1 << " - reservoir(" << reservoirs[i].GetName() << ')' << endl;
		}

		return true;
	}
	else cout << "The list of reservoirs is empty!" << endl;

	return false;

}

int ChoosingReservoir(vector<Reservoir>& reservoirs) {
	int choice_reserv = 1;

	do {

		if (choice_reserv >= 1 && choice_reserv <= reservoirs.size())cout << "Enter your choice: ";
		else cout << "There is no such choice!\nEnter your choice again: ";

		cin >> choice_reserv;

		ClearScrean();
		PrintAllReservoir(reservoirs);

	} while (choice_reserv < 1 || choice_reserv > reservoirs.size());

	return --choice_reserv;
}

void PrintCharactReservoir(vector<Reservoir>& reservoirs) {

	if (PrintAllReservoir(reservoirs) == true) {

		int choice_reserv = ChoosingReservoir(reservoirs);

		ClearScrean();
		cout << "Characteristics " << choice_reserv + 1 << "-th reservoir" << endl;

		cout << "Name: " << reservoirs[choice_reserv].GetName() << endl;

		cout << "Lenght: " << reservoirs[choice_reserv].GetLenght() << " m" << endl;

		cout << "Width: " << reservoirs[choice_reserv].GetWidth() << " m" << endl;

		cout << "Maximal depth: " << reservoirs[choice_reserv].GetMaxDepth() << " m" << endl;

	}

}

Reservoir AddReservoir() {

	char name[50];

	double lenght, width, max_depth;

	cin.ignore();
	cout << "Enter name new reservoir: "; cin.getline(name, 50);

	cout << "Enter lenght new reservoir(m): "; cin >> lenght;

	cout << "Enter width new reservoir(m): "; cin >> width;

	cout << "Enter maximal depth new reservoir(m): "; cin >> max_depth;

	Reservoir reservoir{ name, lenght, width, max_depth };

	return reservoir;

}

vector<Reservoir> DeleteReservoir(vector<Reservoir>& reservoirs) {

	PrintAllReservoir(reservoirs);
	int index = ChoosingReservoir(reservoirs);

	vector<Reservoir> reservoir;
	for (int i = 0; i != reservoirs.size(); i++)if(i!=index)reservoir.push_back(reservoirs[i]);

	ClearScrean();
	cout << "Removal was successful!" << endl;

	return reservoir;//—делал так, потому-что при использовании erase дл€ reservoirs в и вне функции деструктор срабатывал дл€ елементов которые не удал€ютьс€ и выводильс€ мусор:/
}

void VolumeReservoir(vector<Reservoir>& reservoirs) {
	if (PrintAllReservoir(reservoirs) == true) {

		int index = ChoosingReservoir(reservoirs);

		ClearScrean(); 
		cout << "The approximate volume of " << index + 1 << "-th reservoir is: " 
			 << reservoirs[index].GetLenght() * reservoirs[index].GetWidth() * reservoirs[index].GetMaxDepth()
			 << " m^3" << endl;
	}
}

void AreaReservoir(vector<Reservoir>& reservoirs) {
	if (PrintAllReservoir(reservoirs) == true) {

		int index = ChoosingReservoir(reservoirs);

		ClearScrean();
		cout << "The area of " << index + 1 << "-th reservoir(" << reservoirs[index].GetName() << ") is: "
			 << reservoirs[index].GetLenght() * reservoirs[index].GetWidth() << " m^2" << endl;
	}
}

void OfRelativityReservoirs(vector<Reservoir>& reservoirs) {

	if (PrintAllReservoir(reservoirs) == true) {

		int index[2];
		for(int i=0;i!=2;i++)index[i] = ChoosingReservoir(reservoirs);

		ClearScrean();
		cout << "These reservoirs ";
		reservoirs[index[0]].GetName() == reservoirs[index[1]].GetName() ? cout << "applies" : cout << "not applies";
		cout << " to one type" << endl;

	}
}

void AreaComparisonReservoirs(vector<Reservoir>& reservoirs) {

	if (PrintAllReservoir(reservoirs) == true) {

		int index[2];
		for (int i = 0; i != 2; i++)index[i] = ChoosingReservoir(reservoirs);

		if (reservoirs[index[0]].GetName() == reservoirs[index[1]].GetName()) {
			double area[2]{
				reservoirs[index[0]].GetWidth() * reservoirs[index[0]].GetLenght() ,
				reservoirs[index[1]].GetWidth() * reservoirs[index[1]].GetLenght()
			};

			ClearScrean();
			cout << "At " << index[0] + 1 << " reservoir(" << reservoirs[index[0]].GetName() << ") area(" << area[0] << ") ";

			area[0] > area[1] ? cout << "more than" : area[0] < area[1] ? cout << "less than" : cout << "equal to";
			cout << " area (" << area[1] << ") " << index[1] + 1 << " reservoir(" << reservoirs[index[1]].GetName() << ')' << endl;
		}
		else cout << "Types of reservoirs spill!" << endl;
	}
}

void CopyingReservoirs(vector<Reservoir>& reservoirs) {

	if (PrintAllReservoir(reservoirs) == true) {

		int index[2];
		for (int i = 0; i != 2; i++)index[i] = ChoosingReservoir(reservoirs);

		reservoirs[index[0]].CopyInfo(reservoirs[index[1]]);

		ClearScrean();
		cout << "Copying was successful!" << endl;
	}
}

int main() {

	vector<Reservoir> reservoirs;
	int choice = 0;
	do {

		do {

			ClearScrean();
			cout << "Action\n[1] - Add new reservoir\n[2] - Print characteristics reservoir\n"
				 << "[3] - Print all reservoir\n[4] - Delete reservoir\n"
				 << "[5] - Volume definitions\n[6] - Determination of water surface area\n"
				 << "[7] - Do bodies of water belong to the same type\n"
				 << "[8] - Comparison of water surface area of reservoirs one type\n"
				 << "[9] - Copying objects(1 - inserted;2 - copied)\n[0] - Exit" << endl;

			if (choice >= 0 && choice <= 9)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 9);

		ClearScrean();

		switch (choice) {

		case 1:reservoirs.push_back(AddReservoir()); break;

		case 2:PrintCharactReservoir(reservoirs); break;

		case 3:PrintAllReservoir(reservoirs); break;

		case 4:if (reservoirs.size() != 0)reservoirs = DeleteReservoir(reservoirs);
			   else PrintAllReservoir(reservoirs);
			   break;

		case 5: VolumeReservoir(reservoirs); break;

		case 6:AreaReservoir(reservoirs); break;

		case 7:OfRelativityReservoirs(reservoirs); break;

		case 8:AreaComparisonReservoirs(reservoirs); break;

		case 9:CopyingReservoirs(reservoirs); break;

		}

		if(choice != 0)Enter();

	} while (choice != 0);

	return 0;
}