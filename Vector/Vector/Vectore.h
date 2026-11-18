#pragma once

template <typename T>
class TVector
{
private:
    T* arr;
    size_t m_size;
    size_t m_capacity;

    void resize()
    {
        size_t new_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* new_arr = new T[new_capacity];

        for (size_t i = 0; i < m_size; ++i)
        {
            new_arr[i] = std::move(arr[i]);
        }

        delete[] arr;
        arr = new_arr;
        m_capacity = new_capacity;
    }

public:
    TVector() : arr(nullptr), m_size(0), m_capacity(0)
    {
    }

    explicit TVector(size_t size) : m_size(size), m_capacity(size)
    {
        arr = (size > 0) ? new T[size]() : nullptr;
    }

    TVector(size_t size, const T& element) : m_size(size), m_capacity(size)
    {
        arr = (size > 0) ? new T[size] : nullptr;
        for (size_t i = 0; i < size; ++i)
        {
            arr[i] = element;
        }
    }

    ~TVector()
    {
        delete[] arr;
    }

    TVector(const TVector& other)
        : arr(new T[other.m_capacity]), m_size(other.m_size), m_capacity(other.m_capacity)
    {
        for (size_t i = 0; i < m_size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }

    TVector& operator=(const TVector& other)
    {
        if (this != &other)
        {
            T* new_arr = new T[other.m_capacity];
            for (size_t i = 0; i < other.m_size; ++i)
            {
                new_arr[i] = other.arr[i];
            }
            delete[] arr;
            arr = new_arr;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
        }
        return *this;
    }

    TVector(TVector&& other) noexcept
        : arr(other.arr), m_size(other.m_size), m_capacity(other.m_capacity)
    {
        other.arr = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }

    TVector& operator=(TVector&& other) noexcept
    {
        if (this != &other)
        {
            delete[] arr;
            arr = other.arr;
            m_size = other.m_size;
            m_capacity = other.m_capacity;

            other.arr = nullptr;
            other.m_size = 0;
            other.m_capacity = 0;
        }
        return *this;
    }

    void push_back(const T& element)
    {
        if (m_size >= m_capacity)
        {
            resize();
        }
        arr[m_size++] = element;
    }

    void push_back(T&& element)
    {
        if (m_size >= m_capacity)
        {
            resize();
        }
        arr[m_size++] = std::move(element);
    }

    void pop_back()
    {
        if (m_size > 0)
        {
            m_size--;
        }
    }

    void remove(size_t index)
    {
        if (index >= m_size)
        {
            throw std::out_of_range("Indice hors limites");
        }

        for (size_t i = index; i < m_size - 1; ++i)
        {
            arr[i] = std::move(arr[i + 1]);
        }
        m_size--;
    }

    void insert(size_t index, const T& element)
    {
        if (index > m_size)
        {
            throw std::out_of_range("Indice hors limites");
        }

        if (m_size >= m_capacity)
        {
            resize();
        }

        for (size_t i = m_size; i > index; --i)
        {
            arr[i] = std::move(arr[i - 1]);
        }

        arr[index] = element;
        m_size++;
    }

    void insert(size_t index, const T* items, size_t count)
    {
        if (index > m_size)
        {
            throw std::out_of_range("Indice hors limites");
        }
        if (count == 0) return;

        while (m_size + count > m_capacity)
        {
            resize();
        }

        for (size_t i = m_size; i > index; --i)
        {
            arr[i + count - 1] = std::move(arr[i - 1]);
        }

        for (size_t i = 0; i < count; ++i)
        {
            arr[index + i] = items[i];
        }

        m_size += count;
    }

    bool contains(const T& element) const
    {
        for (size_t i = 0; i < m_size; ++i)
        {
            if (arr[i] == element)
            {
                return true;
            }
        }
        return false;
    }

    size_t get_size() const
    {
        return m_size;
    }

    size_t get_capacity() const
    {
        return m_capacity;
    }

    T& operator[](size_t index)
    {
        return arr[index];
    }

    const T& operator[](size_t index) const
    {
        return arr[index];
    }

    T* begin() { return arr; }
    const T* begin() const { return arr; }

    T* end() { return arr + m_size; }
    const T* end() const { return arr + m_size; }
};