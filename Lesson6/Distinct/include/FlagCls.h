#ifndef FLAGCLS_H
#define FLAGCLS_H

template <typename T, int Size>
class FlagCls
{
    public:
        /** Default constructor */
        FlagCls()
        {

        }

        /** Default destructor */
        virtual ~FlagCls()
        {

        }

    protected:

        BitSet();

        Set(T type)
        {

        }

        Clear(T type)
        {

        }

    private:
        int Cnt[(Size / 32)];
};

#endif // FLAGCLS_H
