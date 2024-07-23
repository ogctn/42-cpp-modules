# include "Data.hpp"
# include "Serializer.hpp"

void printData(Data *data);

int main() {
	Data d1 = {1881, 12.21, 25.52f, "ogcetin"};
	std::cout << "--> Original Data" << std::endl;
	printData(&d1);

	{
		std::cout << "\n----  1  ----" << std::endl;
		Data data = d1; Data *deserializedData = NULL;	uintptr_t serialized = 0;
		std::cout << "Data address before serialization: " << &data << std::endl;

		serialized = Serializer::serialize(&data);
		std::cout << "serialized!" << std::endl;
		deserializedData = Serializer::deserialize(serialized);
		std::cout << "deserialized!" << std::endl;
		const_cast<std::string &>(deserializedData->s) = "oguzalp_cetin";
		std::cout << "Data address after serialization:  " << deserializedData << std::endl;
		printData(deserializedData);
	}

	{
		std::cout << "\n----  2  ----" << std::endl;
		Data data = d1; Data *deserializedData = NULL;
		std::cout << "Data address before serialization: " << &data << std::endl;

		deserializedData = Serializer::deserialize(Serializer::serialize(&data));

		std::cout << "Data address after serialization:  " << deserializedData << std::endl;
		const_cast<std::string &>(deserializedData->s) = "__ogctn__";
		deserializedData->i = 17; deserializedData->d = 0.3;
		printData(deserializedData);
	}

	return 0;
}


void printData(Data *data)
{
	if (!data)
	{
		std::cout << "Data is NULL" << std::endl;
		return ;
	}
	std::cout << "Data:\ni:\td:\tf:\ts:" << std::endl;
	std::cout << data->i << "\t" << data->d << "\t" 
			<< data->f << "\t" << data->s << std::endl;
}
