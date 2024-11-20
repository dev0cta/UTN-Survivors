#include "clsArchivoStatistics.h"

ArchivoStatistics::ArchivoStatistics(std::string filePath)
{
	_filePath = filePath;
}

bool ArchivoStatistics::Save(Statistics statistics)
{
    FILE* p = fopen("statistics.dat", "wb+");
    if (p == NULL) {
        return false;
    }

    
    bool ok = fwrite(&statistics, sizeof(Statistics), 1, p);
    fclose(p);
    return ok;
}

Statistics ArchivoStatistics::Read()
{
    FILE* pArchivo = fopen("statistics.dat", "rb");
    if (pArchivo == NULL) {
        return Statistics(0,0,0,0,0,0,0,0,0);
    }
    Statistics statistics;
    fread(&statistics, sizeof(Statistics), 1, pArchivo);
    fclose(pArchivo);
    std::cout << "read : ";
    statistics.coutStatistics(statistics);
    return statistics;
}

void ArchivoStatistics::addAndSaveRecentMatch(Statistics statistics)
{
    Statistics lastRecord(Read());

    lastRecord += statistics;

    if (Save(lastRecord)) {
        std::cout << "RecentMatch added succesfully" << std::endl;
    }
    std::cout << "lastRecord : ";

    lastRecord.coutStatistics(lastRecord);


}


