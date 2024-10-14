#pragma once

// ���ø� Ŭ���� ���鶧�� ��
typedef class AActor* DataType;

class ActorVector
{
    // ��� CPP ������ ���� �ʰڽ��ϴ�.
public:
    int size()
    {
        return DataSize;
    }

	void push_back(DataType _Data)
	{
        DataType* PrevValues = Values;
        Values = new DataType[DataSize + 1];

        for (size_t i = 0; i < DataSize; i++)
        {
            Values[i] = PrevValues[i];
        }

        if (nullptr != PrevValues)
        {
            delete[] PrevValues;
            PrevValues = nullptr;
        }

        Values[DataSize] = _Data;
        ++DataSize;
	}

    void Delete(int _idx)
    {
        int newSize = DataSize - 1;
        
        if (newSize == 0) {
            return;
        }

        DataType* PrevValues = Values;
        Values = new DataType[newSize];

        int newIdx = 0;
        for (size_t i = 0; i < DataSize; i++)
        {
            if (i != _idx && newIdx < newSize)
            {
                Values[newIdx++] = PrevValues[i];
            }
        }

        if (nullptr != PrevValues)
        {
            delete[] PrevValues;
            PrevValues = nullptr;
        }

        DataSize = newSize;
    }

    AActor* operator[](int _Index)
    {
        return Values[_Index];
    }

private:
	DataType* Values;
	int DataSize = 0;
};

