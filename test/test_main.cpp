#include <Arduino.h>
#include <unity.h>

String APP_NAME;

void setUp(void)
{
    // set stuff up here
    APP_NAME = "Hello, Arduino Elevator";
}

void tearDown(void)
{
    // clean stuff up here
    APP_NAME = "";
}

void test_string_concat(void)
{
    String hello = "Hello, ";
    String app = "Arduino Elevator";
    TEST_ASSERT_EQUAL_STRING(APP_NAME.c_str(), (hello + app).c_str());
}

void test_string_substring(void)
{
    TEST_ASSERT_EQUAL_STRING("Hello", APP_NAME.substring(0, 5).c_str());
}

void test_string_index_of(void)
{
    TEST_ASSERT_EQUAL(7, APP_NAME.indexOf('w'));
}

void test_string_equal_ignore_case(void)
{
    TEST_ASSERT_TRUE(APP_NAME.equalsIgnoreCase("HELLO, WORLD!"));
}

void test_string_to_upper_case(void)
{
    APP_NAME.toUpperCase();
    TEST_ASSERT_EQUAL_STRING("HELLO, WORLD!", APP_NAME.c_str());
}

void test_string_replace(void)
{
    APP_NAME.replace('!', '?');
    TEST_ASSERT_EQUAL_STRING("Hello, world?", APP_NAME.c_str());
}

void setup()
{
    delay(2000); // service delay
    UNITY_BEGIN();

    RUN_TEST(test_string_concat);
    //RUN_TEST(test_string_substring);
    //RUN_TEST(test_string_index_of);
    //RUN_TEST(test_string_equal_ignore_case);
    //RUN_TEST(test_string_to_upper_case);
    //RUN_TEST(test_string_replace);

    UNITY_END(); // stop unit testing
}

void loop()
{
}